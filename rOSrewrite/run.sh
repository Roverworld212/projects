cd /media/sf_rKern/rOSrewrite
as --32 ./boot.s -o ./COMPF/boot.o

gcc -w -m32 -c ./kernel.c -o ./COMPF/kernel.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra

ld -m elf_i386 -T linker.ld ./COMPF/kernel.o ./COMPF/boot.o -o ./rOS.bin -nostdlib

grub-file --is-x86-multiboot rOS.bin

mkdir -p ./isodir/boot/grub
cp ./rOS.bin ./isodir/boot/rOS.bin
cp ./grub.cfg ./isodir/boot/grub/grub.cfg
grub-mkrescue -o ./rOS.iso ./isodir
