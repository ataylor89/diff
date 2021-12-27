#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES 0
#define CHARACTERS 1

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];
        printf("argv[%d]: %s\n", i, arg);

        if (strcmp(arg, "-b") == 0 || strcmp(arg, "--bytes") == 0) {
            printf("Mode: %s\n", "Bytes");
        }
        else if (strcmp(arg, "-c") == 0 || strcmp(arg, "--characters") == 0) {
            printf("Mode: %s\n", "Characters");
        }
    }
   
    return 0;
}