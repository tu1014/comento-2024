/home/tu1014/comento/2024/qemu/build/qemu-system-aarch64 \
-kernel /home/tu1014/comento/2024/linux/arch/arm64/boot/Image \
-drive format=raw,file=/home/tu1014/comento/2024/buildroot/output/images/rootfs.ext4,if=virtio \
-append "root=/dev/vda console=ttyAMA0" \
-nographic -M virt -cpu cortex-a72 \
-m 2G \
-smp 2
