#include <string.h>
#include <ctype.h>
#include "autokey.h"

void autokey_encrypt(const char *text, const char *key, char *output) {
    int text_len = strlen(text);
    int key_len = strlen(key);

    // Compose the full key
    char fullkey[text_len];
    strcpy(fullkey, key);

    int chars_to_append = text_len - key_len;
    if (chars_to_append > 0) {
        strncat(fullkey, text, chars_to_append);
    }

    for (int i = 0; i < text_len; i++) {
        char t = text[i];
        char base = isupper(t) ? 'A' : 'a';
        char k = toupper(fullkey[i]);

        if (isalpha(t)) {
            output[i] = ((t - base + k - 'A') % 26) + base;
        } else {
            output[i] = text[i];  // Keep non-alphabet characters unchanged
        }
    }
    output[text_len] = '\0';
}

void autokey_decrypt(const char *ciphertext, const char *key, char *plaintext) {
    int len = strlen(ciphertext);
    char current_key[len];
    strcpy(current_key, key);

    for (int i = 0; i < len; i++) {
        char c = ciphertext[i];
        char base = isupper(ciphertext[i]) ? 'A' : 'a';
        char k = toupper(current_key[i]) - 'A';
        if (isalpha(c)) {
            char p = (char)(((c - base - k + 26) % 26) + base);
            plaintext[i] = p;
            strncat(current_key, &p, 1);  // Append decrypted char to key
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0';
}