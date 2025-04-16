#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "gronsfeld.h"

void gronsfeld_encrypt(const char *plaintext, const char *key, char *result) {
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; plaintext[i]; i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {
            int base = isupper(ch) ? 'A' : 'a';
            if(!isdigit(key[j % key_len])) {
                printf("Invalid key.");
                exit(0);
            }
            int k = key[j % key_len] - '0';

            result[i] = (ch - base + k) % 26 + base;
            j++;
            
        } else {
            result[i] = ch;
        }
    }
    result[strlen(plaintext)] = '\0';
}

void gronsfeld_decrypt(const char *ciphertext, const char *key, char *result) {
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; ciphertext[i]; i++) {
        char ch = ciphertext[i];

        if (isalpha(ch)) {
            int base = isupper(ch) ? 'A' : 'a';
            if(!isdigit(key[j % key_len])) {
                printf("Invalid key.");
                exit(0);
            }
            int k = key[j % key_len] - '0';

            result[i] = (ch - base - k) % 26 + base;
            j++;
            
        } else {
            result[i] = ch;
        }
    }
    result[strlen(ciphertext)] = '\0';
}
