#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "route.h"

// Fill characters to pad the grid
#define FILLER_CHAR 'x'

void routecipher_encrypt(const char *plaintext, int key, char *output) {
    int len = strlen(plaintext);
    int rows = (len + key - 1) / key;

    char grid[rows][key];
    int index = 0;

    // Fill grid row-wise
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < key; c++) {
            if (index < len)
                grid[r][c] = plaintext[index++];
            else
                grid[r][c] = FILLER_CHAR;
        }
    }

    // Read column-wise for encryption
    index = 0;
    for (int c = 0; c < key; c++) {
        for (int r = 0; r < rows; r++) {
            output[index++] = grid[r][c];
        }
    }
    output[index] = '\0';
}

void routecipher_decrypt(const char *ciphertext, int key, char *output) {
    int len = strlen(ciphertext);
    int rows = (len + key - 1) / key;

    char grid[rows][key];
    int index = 0;

    // Fill grid column-wise
    for (int c = 0; c < key; c++) {
        for (int r = 0; r < rows; r++) {
            if (index < len)
                grid[r][c] = ciphertext[index++];
            else
                grid[r][c] = FILLER_CHAR;
        }
    }

    // Read row-wise for decryption
    index = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < key; c++) {
            output[index++] = grid[r][c];
        }
    }
    output[index] = '\0';
}
