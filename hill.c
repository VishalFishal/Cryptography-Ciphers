#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hill.h"

int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int determinant(int key[2][2]) {
    return mod26(key[0][0]*key[1][1] - key[0][1]*key[1][0]);
}

int mod_inverse2(int a, int m) {
    for (int i = 1; i < m; i++)
        if (mod26(a * i) == 1)
            return i;
    return -1;
}

void hill_encrypt(const char* plaintext, int key[2][2], char* output) {
    int len = strlen(plaintext);
    char clean[len];
    int k = 0;

    // Clean input: only alphabetic characters, make lowercase
    for (int i = 0; i < len; i++)
        if (isalpha(plaintext[i]))
            clean[k++] = tolower(plaintext[i]);
    if (k % 2 != 0)
        clean[k++] = 'x';  // padding
    clean[k] = '\0';

    // Encrypt
    for (int i = 0; i < k; i += 2) {
        int a = clean[i] - 'a';
        int b = clean[i+1] - 'a';
        int x = mod26(key[0][0]*a + key[0][1]*b);
        int y = mod26(key[1][0]*a + key[1][1]*b);
        output[i] = x + 'a';
        output[i+1] = y + 'a';
    }
    output[k] = '\0';
}

int hill_decrypt(const char* ciphertext, int key[2][2], char* output) {
    int len = strlen(ciphertext);
    if (len % 2 != 0) return 0;

    int det = determinant(key);
    int det_inv = mod_inverse2(det, 26);
    if (det_inv == -1) return 0;

    // Find inverse matrix mod 26
    int inv[2][2];
    inv[0][0] =  key[1][1] * det_inv;
    inv[0][1] = -key[0][1] * det_inv;
    inv[1][0] = -key[1][0] * det_inv;
    inv[1][1] =  key[0][0] * det_inv;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            inv[i][j] = mod26(inv[i][j]);

    // Decrypt
    for (int i = 0; i < len; i += 2) {
        int a = tolower(ciphertext[i]) - 'a';
        int b = tolower(ciphertext[i+1]) - 'a';
        int x = mod26(inv[0][0]*a + inv[0][1]*b);
        int y = mod26(inv[1][0]*a + inv[1][1]*b);
        output[i] = x + 'a';
        output[i+1] = y + 'a';
    }
    output[len] = '\0';
    return 1;
}
