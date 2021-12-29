#include <stdio.h>

void print_file(char *filename) {

}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./%s <filename>\n", argv[0]);
        return 0;
    }
    print_file(argv[1]);
    return 0;
}