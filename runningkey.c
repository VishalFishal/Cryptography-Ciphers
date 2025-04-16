#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "runningkey.h"

void running_key_encrypt(const char* plaintext, const char* key, char* output) {
    int pt_len = strlen(plaintext);
    int key_len = strlen(key);

    if (key_len < pt_len) {
        strcpy(output, "ERROR: Key is too short for the plaintext.");
        return;
    }

    for (int i = 0, j = 0; i < pt_len; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char k = tolower(key[j]) - 'a';
            output[i] = ((ch - base + k) % 26) + base;
            j++;
        } else {
            output[i] = ch;
        }
    }
    output[pt_len] = '\0';
}

void running_key_decrypt(const char* ciphertext, const char* key, char* output) {
    int ct_len = strlen(ciphertext);
    int key_len = strlen(key);

    if (key_len < ct_len) {
        strcpy(output, "ERROR: Key is too short for the ciphertext.");
        return;
    }

    for (int i = 0, j = 0; i < ct_len; i++) {
        char ch = ciphertext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char k = tolower(key[j]) - 'a';
            output[i] = ((ch - base - k + 26) % 26) + base;
            j++;
        } else {
            output[i] = ch;
        }
    }
    output[ct_len] = '\0';
}
