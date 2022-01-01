#include <stdio.h>

int main(int argc, char **argv) {
    for (int i = 0; i < 10; i++) {
        unsigned long l = (unsigned long) i;
        printf("%08lx\n", l);
    }
    return 0;
}