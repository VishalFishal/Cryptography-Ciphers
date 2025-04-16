#include <ctype.h>
#include <string.h>
#include "affine.h"

int mod_inverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1)
            return i;
    }
    return -1; // no modular inverse
}

void affine_encrypt(const char* input, int a, int b, char* result) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            result[i] = (char)((a * (ch - base) + b) % 26 + base);
        } else {
            result[i] = ch;
        }
    }
    result[strlen(input)] = '\0';
}

void affine_decrypt(const char* input, int a, int b, char* result) {
    int a_inv = mod_inverse(a, 26);
    if (a_inv == -1) {
        strcpy(result, "Error: 'a' has no modular inverse (must be coprime with 26)");
        return;
    }

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            result[i] = (char)((a_inv * ((ch - base - b + 26)) % 26) + base);
        } else {
            result[i] = ch;
        }
    }
    result[strlen(input)] = '\0';
}
