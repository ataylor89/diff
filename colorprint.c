#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define RED 0
#define GREEN 1
#define YELLOW 2
#define BLUE 3
#define MAGENTA 4
#define CYAN 5

void colorprint(char *str, char *color) {
    if (strcmp(color, "red") == 0) {
        printf(ANSI_COLOR_RED);
        printf("%s", str);
        printf(ANSI_COLOR_RESET);
        printf("\n");
    } else if (strcmp(color, "green") == 0) {
        printf(ANSI_COLOR_GREEN);
        printf("%s", str);
        printf(ANSI_COLOR_RESET);
        printf("\n");
    } else if (strcmp(color, "yellow") == 0) {
        printf(ANSI_COLOR_YELLOW);
        printf("%s", str);
        printf(ANSI_COLOR_RESET);
        printf("\n");
    } else if (strcmp(color, "blue") == 0) {
        printf(ANSI_COLOR_BLUE);
        printf("%s", str);
        printf(ANSI_COLOR_RESET);
        printf("\n");
    }
    else if (strcmp(color, "magenta") == 0) {
        printf(ANSI_COLOR_MAGENTA);
        printf("%s", str);
        printf(ANSI_COLOR_RESET);
        printf("\n");
    }
    else if (strcmp(color, "cyan") == 0) {
        printf(ANSI_COLOR_CYAN);
        printf("%s", str);
        printf(ANSI_COLOR_RESET);
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <string> <color>", argv[0]);
        return 0;
    }
    /*for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }*/
    colorprint(argv[1], argv[2]);
    return 0;
}