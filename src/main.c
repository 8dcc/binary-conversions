#include <stdio.h>
#include <ctype.h>     // tolower()
#include <math.h>      // pow()
#include <stdlib.h>    // atoi()
#include <string.h>    // strcmp()

#include "conversors.h"

static inline void print_help(const char* argv0);
static inline void die(const char* s);
static inline void print_dec(int num);
static inline void print_bin(long long num);
static inline void print_oct(int num);
static inline void print_hex(const char* num);
static inline void switch_dec(char target, int num);
static inline void switch_bin(char target, long long num);
static inline void switch_oct(char target, int num);
static inline void switch_hex(char target, const char* num);

int main(int argc, char** argv) {
    // If not enough args or help
    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        print_help(argv[0]);
        return 1;
    }

    if (argc == 3) {    // Only 2 args, unit and number, show all other units
        // Check what are we trying to convert
        switch (tolower(argv[1][0])) {
            case 'd': {
                int num = atoi(argv[2]);
                print_dec(num);
                return 0;
            }
            case 'b': {
                long long num = atoll(argv[2]);
                print_bin(num);
                return 0;
            }
            case 'o': {
                int num = atoi(argv[2]);
                print_oct(num);
                return 0;
            }
            case 'h': {
                print_hex(argv[2]);
                return 0;
            }
            default:
                die("Unknown options. See --help for more info.");
        }
    } else if (argc >= 4) {    // 3 args, unit, target unit and number
        switch (tolower(argv[1][0])) {
            case 'd': {
                int num = atoi(argv[3]);
                switch_dec(argv[2][0], num);
                return 0;
            }
            case 'b': {
                long long num = atoll(argv[3]);
                switch_bin(argv[2][0], num);
                return 0;
            }
            case 'o': {
                int num = atoi(argv[3]);
                switch_oct(argv[2][0], num);
                return 0;
            }
            case 'h': {
                switch_hex(argv[2][0], argv[3]);
                return 0;
            }
            default:
                die("Unknown options. See --help for more info.");
        }
    }

    return 0;
}

void print_help(const char* argv0) {
    printf("Usage:\n");
    printf("    %s d <decimal num>\n", argv0);
    printf("    %s b <binary num>\n", argv0);
    printf("    %s o <octal num>\n", argv0);
    printf("    %s h <hexadecimal str>\n\n", argv0);

    printf("Specific conversions:\n");
    printf("    %s d b <decimal num>\n", argv0);
    printf("    %s d o <decimal num>\n", argv0);
    printf("    %s d h <decimal num>\n", argv0);
    printf("    %s b d <binary num>\n", argv0);
    printf("    %s b o <binary num>\n", argv0);
    printf("    %s b h <binary num>\n", argv0);
    printf("    %s o d <octal num>\n", argv0);
    printf("    %s o b <octal num>\n", argv0);
    printf("    %s o h <octal num>\n", argv0);
    printf("    %s h d <hexadecimal str>\n", argv0);
    printf("    %s h b <hexadecimal str>\n", argv0);
    printf("    %s h o <hexadecimal str>\n", argv0);
}

void die(const char* s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

void print_dec(int num) {
    printf("Dec: %d\n", num);
    printf("Bin: %lld\n", dec2bin(num));
    printf("Oct: %d\n", dec2oct(num));
    printf("Hex: %s\n", dec2hex(num));
}

void print_bin(long long num) {
    printf("Dec: %d\n", bin2dec(num));
    printf("Bin: %lld\n", num);
    printf("Oct: %d\n", bin2oct(num));
    printf("Hex: %s\n", bin2hex(num));
}

void print_oct(int num) {
    printf("Dec: %d\n", oct2dec(num));
    printf("Bin: %lld\n", oct2bin(num));
    printf("Oct: %d\n", num);
    printf("Hex: %s\n", oct2hex(num));
}

void print_hex(const char* num) {
    printf("Dec: %d\n", hex2dec(num));
    printf("Bin: %lld\n", hex2bin(num));
    printf("Oct: %d\n", hex2oct(num));
    printf("Hex: %s\n", num);
}

void switch_dec(char target, int num) {
    switch (target) {
        case 'b':
            printf("%lld\n", dec2bin(num));
            break;
        case 'o':
            printf("%d\n", dec2oct(num));
            break;
        case 'h':
            printf("%s\n", dec2hex(num));
            break;
        case 'd':
        default:
            die("Unknown options. See --help for more info.");
            break;
    }
}

void switch_bin(char target, long long num) {
    switch (target) {
        case 'd':
            printf("%d\n", bin2dec(num));
            break;
        case 'o':
            printf("%d\n", bin2oct(num));
            break;
        case 'h':
            printf("%s\n", bin2hex(num));
            break;
        case 'b':
        default:
            die("Unknown options. See --help for more info.");
            break;
    }
}

void switch_oct(char target, int num) {
    switch (target) {
        case 'd':
            printf("%d\n", oct2dec(num));
            break;
        case 'b':
            printf("%lld\n", oct2bin(num));
            break;
        case 'h':
            printf("%s\n", oct2hex(num));
            break;
        case 'o':
        default:
            die("Unknown options. See --help for more info.");
            break;
    }
}

void switch_hex(char target, const char* num) {
    switch (target) {
        case 'd':
            printf("%d\n", hex2dec(num));
            break;
        case 'b':
            printf("%lld\n", hex2bin(num));
            break;
        case 'o':
            printf("%d\n", hex2oct(num));
            break;
        case 'h':
        default:
            die("Unknown options. See --help for more info.");
            break;
    }
}
