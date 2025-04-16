#include <ctype.h>
#include <string.h>
#include "vigenere.h"

void vigenere_encrypt(const char* plaintext, const char* key, char* result) {
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char k = tolower(key[j % key_len]) - 'a';
            result[i] = (char)(((ch - base + k) % 26) + base);
            j++;
        } else {
            result[i] = ch;
        }
    }
    result[strlen(plaintext)] = '\0';
}

void vigenere_decrypt(const char* ciphertext, const char* key, char* result) {
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char k = tolower(key[j % key_len]) - 'a';
            result[i] = (char)(((ch - base - k + 26) % 26) + base);
            j++;
        } else {
            result[i] = ch;
        }
    }
    result[strlen(ciphertext)] = '\0';
}
