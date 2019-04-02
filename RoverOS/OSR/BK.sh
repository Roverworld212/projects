cd <Path_to_RoverOS_folder>
echo "Building boot.asm";
nasm -f -aout -o ./kernel/boot.asm ./OSR/boot.o;
echo "Building kernel";
gcc ./kernel/kernel.c -o ./OSR/kernel.o;
echo "Linking files";
Obviously not finished I will finish it later
