#include <stdio.h>

void print_file(char *filename) {
    FILE *file = fopen(filename, "r");
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    rewind(file);
    char buf[filesize];
    fread(buf, sizeof(char), filesize, file);
    unsigned long l = 0;
    for (int i = 0; i < filesize; i++) {
        printf("%08lx ", l);
        for (int j = 0; j < 16 && i + j < filesize; j++) {
            if (j == 15) 
                printf("%02hhx\n", buf[i+j]);
            else if (i + j == filesize-1)
                printf("%02hhx\n", buf[i+j]);
            else if (j % 2 == 0)
                printf("%02hhx", buf[i+j]);
            else if (j % 2 == 1)
                printf("%02hhx ", buf[i+j]);
        }
        i += 16;
        l += 16L;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./%s <filename>\n", argv[0]);
        return 0;
    }
    print_file(argv[1]);
    return 0;
}