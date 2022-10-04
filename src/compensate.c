/*
 * Reads N lines from stdin (numbers) and adds 0's to the left to nivelate them.
 * Intended for conversor + binary-table.sh
 */

#include <stdio.h>
#include <stdlib.h>

#define ITEM_SEPARATOR '\n'

#define die(s, va)              \
    {                           \
        fprintf(stderr, s, va); \
        exit(1);                \
    }

int get_digits(long long target);

int main(int argc, char** argv) {
    if (argc < 2) die("Not enough arguments.\nUsage: %s <max items>\n", argv[0]);

    int arr_len       = atoi(argv[1]);
    long long* arr    = malloc(arr_len * sizeof(long long));
    long long longest = 0;

    // Read numbers and save in arr. Store the real item ammount in j
    int j;
    for (j = 0; j < arr_len; j++) {
        if (fscanf(stdin, "%lld", &arr[j]) < 0) break;

        if (arr[j] > longest) longest = arr[j];
    }

    int longest_len = get_digits(longest);
    int cur_len     = 0;

    // Iterate arr and print the compensated numbers. j is the real item ammount
    for (int n = 0; n < j; n++) {
        cur_len = get_digits(arr[n]);

        // Print needed 0's
        for (int i = 0; i < longest_len - cur_len; i++) putchar('0');

        printf("%lld%c", arr[n], ITEM_SEPARATOR);
    }

    return 0;
}

int get_digits(long long target) {
    int n   = target;
    int ret = 1;

    while (n > 9) {
        n /= 10;
        ret++;
    }

    return ret;
}
