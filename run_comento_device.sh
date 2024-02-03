~/comento/2024/qemu/build/qemu-system-aarch64 \
-kernel ~/comento/2024/linux/arch/arm64/boot/Image \
-drive format=raw,file=sdcard.img,if=sd \
-append "root=/dev/mmcblk0p1 console=ttyAMA0 rootwait" \
-dtb ~/comento/2024/linux/arch/arm64/boot/dts/comento/comento.dtb \
-qmp unix:/tmp/qmp.sock,server,nowait -nographic -M comento -m 1G -smp 4

