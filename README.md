# diff
There are many programs in this directory
1. diff.c
2. hexdump.c
3. colorprint.c
4. linenumbers.c
5. simple.asm
6. simpleprintf.asm

The assembly program, simple.asm, can be used to create an object file, simple.o, with the following command on Mac OS X:   
nasm -fmacho64 simple.asm -o simple.o

The program nasm assembles the assembly file, simple.asm, into an object file, simple.o

The option -fmacho64 means filetype MachO x86_64, which is a kind of object file (MachO) that has instructions for a 64-bit processor

The option -o gives the path of the object file

The object file simple.o can be linked with the programs ld or gcc, for example
1. ld -macosx_version_min 10.7 simple.o -o simple
2. ld -macosx_version_min 10.7 -lSystem simpleprintf.o -o simpleprintf
3. gcc simple.o -o simple
4. gcc simpleprintf.o -o simpleprintf

The object files can be compared with diff or viewed with hexdump
1. nasm -fmacho64 simple.asm -o simple1.o <br/>
2. nasm -fmacho64 simple.asm -o simple2.o <br/>
3. gcc diff.c -o diff <br/>
4. gcc hexdump.c -o hexdump <br/>
5. ./diff simple1.o simple2.o <br/>
6. ./hexdump simple1.o