
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
        ret *= 10;           // Shift a digits of the ret
        ret += num % 10;     // Append last digit of num
        num /= 10;           // Remove the last digit we just appended
    }

    return ret;
}

// Converts decimal to binary and then to octal
int dec2oct(int num) {
    int ret  = 0;               // Octal result that will be returned
    long bin = dec2bin(num);    // First we convert the decimal arg to binary
    
    while (bin > 0) {
        ret *= 10;                      // Shift digits of the octal ret
        ret += bin2dec(bin % 1000);     // Convert the last 3 digits of the bin to decimal
        bin /= 1000;                    // Remove the last 3 digits from bin
    }

    return reverse_digits(ret);         // We need to revert it because of the order we are converting binary
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

// Returns hex str from decimal int
char* dec2hex(int num) {
    const int max_chars = 12;
    char* ret = calloc(max_chars, sizeof(char)); // Hexadecimal result that will be returned
    long bin = dec2bin(num);                     // First we convert the decimal arg to binary
    
    int strpos = max_chars - 2;
    while (bin > 0 && strpos >= 0) {
        ret[strpos--] += int2hex(bin2dec(bin % 10000));   // Convert the last 3 digits of the bin to decimal and then to hex char
        bin /= 10000;                           // Remove the last 3 digits from bin
    }

    return &ret[strpos+1];
}

