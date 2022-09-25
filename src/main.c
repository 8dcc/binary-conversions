#include <stdio.h>
#include <string.h>

static inline void print_help();

int main(int argc, char** argv) {
    // If not enough args or help
    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        print_help(argv[0]);
    }

    return 0;
}

void print_help(const char* argv0) {
    printf("Usage:\n");
    printf("\t%s d <decimal num>\n", argv0);
    printf("\t%s b <binary num>\n", argv0);
    printf("\t%s o <octal num>\n", argv0);
    printf("\t%s h <hexadecimal str>\n", argv0);
}
