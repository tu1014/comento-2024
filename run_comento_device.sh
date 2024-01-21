/home/tu1014/comento/2024/qemu/build/qemu-system-aarch64 \
-kernel /home/tu1014/comento/2024/linux/arch/arm64/boot/Image \
-initrd /home/tu1014/comento/2024/buildroot/output/images/rootfs.cpio.gz \
-append "console=ttyAMA0" \
-dtb /home/tu1014/comento/2024/linux/arch/arm64/boot/dts/comento/comento.dtb \
-qmp unix:/tmp/qmp.sock,server,nowait \
-nographic -M comento -m 1G -smp 2

