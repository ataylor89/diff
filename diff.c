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

void leftprint(char *buf, int offset, int diff, int padding) {
    if (diff) {
        printf(ANSI_COLOR_RED);
        printf("%02hhx", buf[offset]);
        printf("%*c", padding, ' ');
        printf(ANSI_COLOR_RESET);
    }
    else {
        printf("%02hhx", buf[offset]);
        printf("%*c", padding, ' ');
    }
}

void rightprint(char *buf, int offset, int diff, int padding) {
    if (diff) {
        printf(ANSI_COLOR_GREEN);
        printf("%02hhx", buf[offset]);
        printf("%*c", padding, ' ');
        printf(ANSI_COLOR_RESET);
    }
    else {
        printf("%02hhx", buf[offset]);
        printf("%*c", padding, ' ');
    }
}

void diff(char *f1, char *f2) {
    FILE *file1 = fopen(f1, "r");
    fseek(file1, 0, SEEK_END);
    int filesize1 = ftell(file1);
    rewind(file1);
    char bufA[filesize1];
    fread(bufA, sizeof(char), filesize1, file1);

    FILE *file2 = fopen(f2, "r");
    fseek(file2, 0, SEEK_END);
    int filesize2 = ftell(file2);
    rewind(file2);
    char bufB[filesize2];
    fread(bufB, sizeof(char), filesize2, file2);

    int len = filesize1 > filesize2 ? filesize1 : filesize2;
    unsigned long line_number = 0;

    for (int i = 0; i < len; i++) {
        printf("%08lx ", line_number);
        for (int j = 0; j < 16 && i + j < filesize1; j++) {
            int offset = i+j;
            int diff = 0;
            if (bufA[offset] != bufB[offset])
                diff = 1;
            if (j == 15) 
                leftprint(bufA, offset, diff, 4);
            else if (i + j == filesize1-1)
                leftprint(bufA, offset, diff, 4+2*(15-j)+(15-j));
            else if (j % 2 == 1)
                leftprint(bufA, offset, diff, 1);
            else 
                leftprint(bufA, offset, diff, 0);
        }
        for (int j = 0; j < 16 && i + j < filesize2; j++) {
            int offset = i+j;
            int diff = 0;
            if (bufA[offset] != bufB[offset])
                diff = 1;
            if (j == 15) 
                rightprint(bufB, offset, diff, 0);
            else if (i + j == filesize2-1)
                rightprint(bufB, offset, diff, 0);
            else if (j % 2 == 1)
                rightprint(bufB, offset, diff, 1);
            else 
                rightprint(bufB, offset, diff, 0);
        }
        printf("\n");
        i += 16;
        line_number += 16L;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 0;
    }
    diff(argv[1], argv[2]);
    return 0;
}