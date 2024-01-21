
#include "twa.h"

static void create_uart(const TwaMachineState *vms, MemoryRegion *mem)
{
    hwaddr base;
    int irq = TWA_IRQ_UART;
    DeviceState *dev;
    SysBusDevice *s;

    // UART 1
    base = TWA_BASE_UART;
    dev = qdev_new(TYPE_PL011);
    s = SYS_BUS_DEVICE(dev);
    qdev_prop_set_chr(dev, "chardev", serial_hd(0));
    sysbus_realize_and_unref(s, &error_fatal);
    memory_region_add_subregion(mem, base, sysbus_mmio_get_region(s, 0));
    sysbus_connect_irq(s, 0, qdev_get_gpio_in(vms->gic, irq));

    // UART 2
    base = TWA_BASE_UART2;
    dev = qdev_new(TYPE_PL011);
    s = SYS_BUS_DEVICE(dev);
    qdev_prop_set_chr(dev, "chardev", serial_hd(1));
    sysbus_realize_and_unref(s, &error_fatal);
    memory_region_add_subregion(mem, base, sysbus_mmio_get_region(s, 0));
    sysbus_connect_irq(s, 0, qdev_get_gpio_in(vms->gic, irq));
}

static void create_gic(TwaMachineState *vms)
{
    MachineState *ms = MACHINE(vms);
    SysBusDevice *gicbusdev;
    unsigned int smp_cpus = ms->smp.cpus;

    vms->gic = qdev_new("arm-gicv3");

    qdev_prop_set_uint32(vms->gic, "revision", 3);
    qdev_prop_set_uint32(vms->gic, "num-cpu", smp_cpus);
    qdev_prop_set_uint32(vms->gic, "num-irq", NUM_IRQS + 32);

    uint32_t redist_capacity = TWA_SIZE_GIC_REDIST / GICV3_REDIST_SIZE;
    uint32_t redist_count = MIN(smp_cpus, redist_capacity);
    qdev_prop_set_uint32(vms->gic, "len-redist-region-count", 1);
    qdev_prop_set_uint32(vms->gic, "redist-region-count[0]", redist_count);

    gicbusdev = SYS_BUS_DEVICE(vms->gic);
    sysbus_realize_and_unref(gicbusdev, &error_fatal);
    sysbus_mmio_map(gicbusdev, 0, TWA_BASE_GIC_DIST);
    sysbus_mmio_map(gicbusdev, 1, TWA_BASE_GIC_REDIST);
    
    int i;
    for (i = 0; i < smp_cpus; i++) {
        DeviceState *cpudev = DEVICE(qemu_get_cpu(i));
        int ppibase = NUM_IRQS + i * GIC_INTERNAL + GIC_NR_SGIS;
        
        qdev_connect_gpio_out(cpudev, 0,
            qdev_get_gpio_in(vms->gic, ppibase + ARCH_TIMER_NS_EL1_IRQ));
        
        sysbus_connect_irq(gicbusdev, i,
            qdev_get_gpio_in(cpudev, ARM_CPU_IRQ));
        
        sysbus_connect_irq(gicbusdev, i + smp_cpus,
            qdev_get_gpio_in(cpudev, ARM_CPU_FIQ));
    }
}


static void machtwa_init(MachineState *machine)
{
    TwaMachineState *vms = TWA_MACHINE(machine);

    // memory
    MemoryRegion *sysmem = get_system_memory();
    memory_region_add_subregion(sysmem, TWA_BASE_MEM, machine->ram);
    
    vms->bootinfo.ram_size = machine->ram_size;
    vms->bootinfo.loader_start = TWA_BASE_MEM;

    // CPUs
    int index;
    unsigned int smp_cpus = machine->smp.cpus;

    for (index = 0; index < smp_cpus; index++) {

        Object *cpuobj;
        CPUState *cs;
        cpuobj = object_new(TWA_CPU_TYPE);

        object_property_set_bool(cpuobj, "has_el3", false, NULL);
        object_property_set_bool(cpuobj, "has_el2", false, NULL);

        if (object_property_find(cpuobj, "reset-cbar")) {
            object_property_set_int(cpuobj, "reset-cbar",
            TWA_BASE_GIC_DIST, &error_abort);
        }

        object_property_set_link(cpuobj, "memory", OBJECT(sysmem),
                &error_abort);
        qdev_realize(DEVICE(cpuobj), NULL, &error_fatal);

        cs = CPU(cpuobj);
        cs->cpu_index = index;

        object_unref(cpuobj);
    }

    vms->bootinfo.psci_conduit = QEMU_PSCI_CONDUIT_HVC;

    // GIC
    create_gic(vms);

    // UART
    create_uart(vms, sysmem);

    arm_load_kernel(ARM_CPU(first_cpu), machine, &vms->bootinfo); // -> 맨 마지막에 실행되어야 한다
}

static void twa_machine_class_init(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);
    mc->desc = "Taewook board";
    mc->init = machtwa_init;
    mc->max_cpus = 128;
    mc->block_default_type = IF_SD;
    mc->no_cdrom = 1;
    mc->minimum_page_bits = 12;
    mc->default_ram_id = "mach-twa.ram";
}

static const TypeInfo twa_machine_info = {
    .name = "twa-machine",
    .parent = TYPE_MACHINE,
    .instance_size = sizeof(TwaMachineState),
    .class_size = sizeof(TwaMachineClass),
    .class_init = twa_machine_class_init,
};

static void machtwa_machine_init(void)
{
    type_register_static(&twa_machine_info);
}

type_init(machtwa_machine_init);
