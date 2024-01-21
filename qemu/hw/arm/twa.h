
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

#define TWA_CPU_TYPE ARM_CPU_TYPE_NAME("cortex-a72")
#define TYPE_TWA_MACHINE MACHINE_TYPE_NAME("twa")

#define NUM_IRQS 256
#define ARCH_TIMER_NS_EL1_IRQ 14

#define TWA_BASE_MEM 0x80000000

#define TWA_BASE_GIC_DIST 0x04000000

#define TWA_BASE_GIC_REDIST 0x03000000
#define TWA_SIZE_GIC_REDIST 0x01000000


#define TWA_IRQ_UART 0
#define TWA_BASE_UART  0x04010000
#define TWA_BASE_UART2 0x04020000


struct TwaMachineClass {
    MachineClass parent;
};

struct TwaMachineState {
    MachineState parent;
    DeviceState *gic;
    struct arm_boot_info bootinfo;
};

OBJECT_DECLARE_TYPE(TwaMachineState, TwaMachineClass, \
                        TWA_MACHINE)

static void machtwa_init(MachineState *machine);
static void twa_machine_class_init(ObjectClass *oc, void *data);
static void machtwa_machine_init(void);
static void create_gic(TwaMachineState *vms);
static void create_uart(const TwaMachineState *vms, MemoryRegion *mem);