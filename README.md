# diff
There are many C programs in this directory
1. diff.c
2. hexdump.c
3. colorprint.c
4. linenumbers.c

The assembly program, simple.asm, can be used to create an object file, simple.o, with the following command on Mac OS X:    
    nasm -fmacho64 simple.asm -o simple.o

The option -fmacho64 means filetype MachO x86_64, which is a kind of object file (MachO) that has instructions for a 64-bit processor

For example,

nasm -fmacho64 simple.asm -o simple1.o
nasm -fmacho64 simple.asm -o simple2.o
gcc diff.c -o diff
gcc hexdump.c -o hexdump
./diff simple1.o simple2.o
./hexdump simple1.o