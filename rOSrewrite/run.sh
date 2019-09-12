cd '/media/sf_rKern/rOSrewrite2'
as --32 ./boot/boot.s -o ./COMPF/boot.o

gcc -w -m32 -c ./kernel/kernel.c -o ./COMPF/kernel.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra
gcc -w -m32 -c ./kernel/setup.c -o ./COMPF/setup.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra
gcc -w -m32 -c ./kernel/io.c -o ./COMPF/io.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra
gcc -w -m32 -c ./kernel/kutils.c -o ./COMPF/kutils.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra
gcc -w -m32 -c ./kernel/ui.c -o ./COMPF/ui.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra
gcc -w -m32 -c ./kernel/utils.c -o ./COMPF/utils.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra
gcc -w -m32 -c ./kernel/panic.c -o ./COMPF/panic.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra
gcc -w -m32 -c ./kernel/programs/terminal.c -o ./COMPF/term.o -I./Include -std=gnu99 -ffreestanding -O2 -Wall -Wextra

ld -m elf_i386 -T linker.ld ./COMPF/kernel.o ./COMPF/panic.o ./COMPF/boot.o ./COMPF/term.o ./COMPF/setup.o ./COMPF/io.o ./COMPF/kutils.o ./COMPF/ui.o ./COMPF/utils.o -o ./rOS.bin -nostdlib

grub-file --is-x86-multiboot rOS.bin

mkdir -p ./isodir/boot/grub
cp ./rOS.bin ./isodir/boot/rOS.bin
cp ./grub.cfg ./isodir/boot/grub/grub.cfg
grub-mkrescue -o ./rOS.iso ./isodir
