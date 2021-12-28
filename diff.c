#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define BYTES 0
#define CHARACTERS 1

int get_file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    return size;
}

char *read_file(FILE *file, int filesize) {
    char *buf = malloc(sizeof(char) * filesize);
    fread(buf, sizeof(char), filesize, file);
    return buf;
}

void diff(char* file1, char* file2, int mode) {
    printf("Running diff on files %s and %s in mode %d\n", file1, file2, mode);
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    int size1 = get_file_size(f1);
    int size2 = get_file_size(f2);
    printf("Size of file1: %d\n", size1);
    printf("Size of file2: %d\n", size2);
    char *buf1 = read_file(f1, size1);
    char *buf2 = read_file(f2, size2);
    
    int len = size1 > size2 ? size1 : size2;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 16 && i+j < size1; j++) {
            unsigned char a = (unsigned char) buf1[i+j];
            unsigned char b = (unsigned char) buf2[i+j];

            char *fmt;
            if (j % 2 == 0)
                fmt = "%02hhx";
            else if (j == 15 || i+j == size1-1)
                fmt = "%02hhx    ";
            else
                fmt = "%02hhx ";

            if (a == b) {
                printf(fmt, a);
            }
            else {
                printf(ANSI_COLOR_RED);
                printf(fmt, a);
                printf(ANSI_COLOR_RESET);
            }
        }
        for (int j = 0; j < 16 && i+j < size2; j++) {
            unsigned char a = (unsigned char) buf1[i+j];
            unsigned char b = (unsigned char) buf2[i+j];
            
            char *fmt;
            if (j % 2 == 0)
                fmt = "%02hhx";
            else if (j == 15 || i+j==size2-1)
                fmt = "%02hhx\n";
            else
                fmt = "%02hhx ";

            if (a == b) {
                printf(fmt, b);
            }
            else {
                printf(ANSI_COLOR_GREEN);
                printf(fmt, b);
                printf(ANSI_COLOR_RESET);
            }
        }
        i += 16;
    }
    fclose(f1);
    fclose(f2);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <options> <file1> <file2>\n", argv[0]);
        return 0;
    }
    for (int i = 0; i < argc; i++) {   
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    printf("size of char: %lu\n", sizeof(char));
    char *file1, *file2;
    int mode = 0;
    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "-b") == 0 || strcmp(arg, "--bytes") == 0) {
            printf("Mode: %s\n", "Bytes");
            mode = BYTES;
        }
        else if (strcmp(arg, "-c") == 0 || strcmp(arg, "--characters") == 0) {
            printf("Mode: %s\n", "Characters");
            mode = CHARACTERS;
        }
        else if (i > 0 && file1 == NULL) {
            printf("File1: %s\n", arg);
            file1 = arg;
        }
        else if (i > 0 && file2 == NULL) {
            printf("File2: %s\n", arg);
            file2 = arg;
        }
    }
    if (file1 != NULL && file2 != NULL)
        diff(file1, file2, mode);   
    else
        printf("Error parsing file1 and file2\n");
    return 0;
}