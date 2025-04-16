#include <ctype.h>
#include "caesar.h"

void caesar_encrypt(char *plaintext, int key, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isupper(ch)) {
            ciphertext[i] = ((ch - 'A' + key) % 26) + 'A';
        } else if (islower(ch)) {
            ciphertext[i] = ((ch - 'a' + key) % 26) + 'a';
        } else {
            ciphertext[i] = ch;
        }
    }
}
   
void caesar_decrypt(char *ciphertext, int key, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (isupper(ch)) {
            plaintext[i] = ((ch - 'A' - key + 26) % 26) + 'A';
        } else if (islower(ch)) {
            plaintext[i] = ((ch - 'a' - key + 26) % 26) + 'a';
        } else {
            plaintext[i] = ch;
        }
    }
}
