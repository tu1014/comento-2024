
#include "qemu/osdep.h"
#include "qemu/datadir.h"
#include "qemu/units.h"
#include "qemu/option.h"
#include "qemu/module.h"
#include "qemu/error-report.h"
#include "qapi/error.h"
#include "hw/boards.h"
#include "hw/sysbus.h"
#include "hw/loader.h"
#include "hw/qdev-properties.h"
#include "hw/arm/boot.h"
#include "sysemu/runstate.h"
#include "sysemu/sysemu.h"
#include "target/arm/cpu.h"
#include "hw/intc/arm_gicv3_common.h"
#include "hw/char/pl011.h"

#define COMENTO_CPU_TYPE ARM_CPU_TYPE_NAME("cortex-a72")
#define TYPE_COMENTO_MACHINE MACHINE_TYPE_NAME("comento")

#define NUM_IRQS 256
#define ARCH_TIMER_NS_EL1_IRQ 14

#define COMENTO_BASE_MEM 0x40000000

#define COMENTO_BASE_GIC_DIST 0x09000000

#define COMENTO_BASE_GIC_REDIST 0x08000000
#define COMENTO_SIZE_GIC_REDIST 0x01000000

#define COMENTO_IRQ_UART 0
#define COMENTO_BASE_UART 0x09010000

#define COMENTO_IRQ_MMIO 1
#define COMENTO_BASE_MMIO 0x09020000


struct ComentoMachineClass {
    MachineClass parent;
};

struct ComentoMachineState {
    MachineState parent;
    DeviceState *gic;
    struct arm_boot_info bootinfo;
};

OBJECT_DECLARE_TYPE(ComentoMachineState, ComentoMachineClass, \
                        COMENTO_MACHINE)

static void machcomento_init(MachineState *machine);
static void comento_machine_class_init(ObjectClass *oc, void *data);
static void machcomento_machine_init(void);
static void create_gic(ComentoMachineState *vms);
static void create_uart(const ComentoMachineState *vms, MemoryRegion *mem);

static void create_mmio(const ComentoMachineState *vms, MemoryRegion *mem);