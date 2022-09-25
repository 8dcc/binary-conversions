
// Decimal to binary
long dec2bin(int num) {
    int ret = 0;        // Binary result that will be returned
    int rem = 0;        // Remainder used when dividing the number
    int f   = 1;        // Factor that will be multiplied by 10 each loop

    while (num != 0) {
        rem  = num % 2; // Get the remainder
        ret += rem * f; // Add it to the next digit of the return (f is the position)
        f   *= 10;      // Increase the digit position by multiplying by 10
        num /= 2;       // Divide the original number
    }

    return ret;
}

int bin2dec(long bin) {
    int ret = 0;        // Decimal result that will be returned
    int rem = 0;        // Remainder that will be used to get each digit
    int p   = 0;        // Power that will be used when increasing ret. Will increase each iteration

    while (bin != 0) {
        rem  = bin % 10;        // Get digit
        bin /= 10;              // Remove digit
        ret += rem * pow(2, p); // Add the digit to the decimal as power
        p++;                    // Increase current power
    }

    return ret;
}

// 123 -> 321
int reverse_digits(int num) {
    int ret = 0;

    while (num > 0) {
        ret *= 10;           // Shift a digit of the ret
        ret += num % 10;     // Append last digit of num
        num /= 10;           // Remove the last digit we just appended
    }

    return ret;
}

int bin2oct(long num);

// Converts decimal to binary and then to octal
int dec2oct(int num) {
    return bin2oct(dec2bin(num));   // We need to revert it because of the order we are converting binary
}

// Returns formated str from octal int. Unused
char* format_oct(int oct) {
    const int charsperdigit = 3;
    const int max_digits    = 10;
    char* ret               = calloc(max_digits * charsperdigit, sizeof(char));     // Final string. Max digits * chars per digit
    int strpos              = max_digits * charsperdigit - 2;                       // -1 cuz of the len and -2 cuz of the ret +1

    // Will iterate from the last char of the string
    while (oct > 0 && strpos >= 0) {
        ret[strpos--]  = (oct % 10) + '0';  // Add char
        oct           /= 10;                // Remove last digit
        for (int n = 0; n < charsperdigit-1; n++)
            ret[strpos--]  = ' ';           // Add spaces spaces before digit
    }

    // Return ptr to the last pos we wrote to
    return &ret[strpos+1];
}

// Returns a single hex char from a decimal integer
char int2hex(int num) {
    if (num < 0) return '0';

    if (num <= 9) return num + '0';
    else          return num - 10 + 'A';
}

char* bin2hex(long num);

// Returns hex str from decimal int
char* dec2hex(int num) {
    return bin2hex(dec2bin(num));
}

/*------------------------------------------------------------*/

int bin2oct(long num) {
    int ret = 0;

    while (num > 0) {
        ret *= 10;                      // Shift digits of the octal ret
        ret += bin2dec(num % 1000);     // Convert the last 3 digits of the num to decimal
        num /= 1000;                    // Remove the last 3 digits from num
    }

    return reverse_digits(ret);
}

char* bin2hex(long num) {
    const int max_chars = 12;
    char* ret = calloc(max_chars, sizeof(char)); // Hexadecimal result that will be returned
    
    int strpos = max_chars - 2;
    while (num > 0 && strpos >= 0) {
        ret[strpos--] += int2hex(bin2dec(num % 10000));   // Convert the last 3 digits of the bin to decimal and then to hex char
        num /= 10000;                                     // Remove the last 3 digits from bin
    }

    return &ret[strpos+1];
}

/*------------------------------------------------------------*/

// Reverts a binary number in sets of 3. Unused
long reverse_oct_bin(long num) {
    long ret = 0;

    while (num > 0) {
        ret *= 1000;        // Shift 3 digits of the ret
        ret += num % 1000;  // Append 3 last digits of num
        num /= 1000;        // Remove the 3 last digits we just appended
    }

    return ret;
}

long oct2bin(int num) {
    long ret     = 0;
    long cur_bin = 0;    // Current digit of the octal converted to binary. Needed to store in case we need to add left 0's
    int digits   = 0;    // We need to shift the array depending on the digits we have

    while (num > 0) {
        cur_bin = dec2bin(num % 10);

        /* Increase the number of digits of the new number:
         *
         * ret = 001 ->    001 |
         * bin = 111 -> 111000 |-> 111001
         *
         * Iterate to avoid multiplying by 0
         */
        for (int n = 0; n < digits; n++)
            cur_bin *= 10;

        ret    += cur_bin;      // Add the new 3 digits to the 'left'
        digits += 3;            // Count the last 3 digits for shifting the next 'cur_bin'
        num    /= 10;           // Remove the last digit from num
    }

    return ret;
}

int oct2dec(int num) {
    return bin2dec(oct2bin(num));
}

char* oct2hex(int num) {
    return bin2hex(oct2bin(num));
}

/*------------------------------------------------------------*/

// Returns an integer from hexchar
int hex2int(char c) {
    c = tolower(c);

    if (c < '0' || c > 'f') return 0;

    if (c <= '9') return c - '0';
    else          return c - 'a' + 10;
}

long hex2bin(const char* str) {
    long ret   = 0;
    int strpos = 0;     // Will increase when converting each char

    // Iterate each char of str and save it in 'c'
    int c = 0;
    while ((c = str[strpos++]) != '\0') {
        // Shift return bin 4 digits
        ret *= 10000;

        // Convert the current pos of the string from left to right to integer and then to binary,
        // then add it to the binary long that will be returned
        ret += dec2bin(hex2int(c));
    }

    return ret;
}

int hex2dec(const char* str) {
    return bin2dec(hex2bin(str));
}

int hex2oct(const char* str) {
    return bin2oct(hex2bin(str));
}
