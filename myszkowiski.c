#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "myszkowiski.h"

// Helper: Assign ranks based on key
void assign_ranks(const char *key, int *rank) {
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        rank[i] = 1;
        for (int j = 0; j < len; j++) {
            if (tolower(key[j]) < tolower(key[i])) rank[i]++;
        }
    }
}

// Encrypt
void myszkowski_encrypt(const char *plaintext, const char *key, char *output) {
    int keylen = strlen(key);
    int textlen = strlen(plaintext);
    int rows = (textlen + keylen - 1) / keylen;

    char matrix[rows][keylen];
    int index = 0;

    // Fill matrix row-wise
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < keylen; c++) {
            if (index < textlen)
                matrix[r][c] = plaintext[index++];
            else
                matrix[r][c] = 'X';  // pad with filler
        }
    }

    // Assign column ranks based on repeating chars
    int rank[keylen];
    assign_ranks(key, rank);

    // Output column-by-column in rank order
    int out_index = 0;
    for (int rank_level = 1; rank_level <= keylen; rank_level++) {
        for (int c = 0; c < keylen; c++) {
            if (rank[c] == rank_level) {
                for (int r = 0; r < rows; r++) {
                    output[out_index++] = matrix[r][c];
                }
            }
        }
    }

    output[out_index] = '\0';
}

// Decrypt
void myszkowski_decrypt(const char *ciphertext, const char *key, char *output) {
    int keylen = strlen(key);
    int textlen = strlen(ciphertext);
    int rows = (textlen + keylen - 1) / keylen;

    char matrix[rows][keylen];
    int rank[keylen];
    assign_ranks(key, rank);

    // Count occurrences of each rank
    int col_count[keylen];
    memset(col_count, 0, sizeof(col_count));
    for (int i = 0; i < keylen; i++) {
        col_count[rank[i] - 1]++;
    }

    // Fill matrix column-wise in rank order
    int index = 0;
    for (int rnk = 1; rnk <= keylen; rnk++) {
        for (int c = 0; c < keylen; c++) {
            if (rank[c] == rnk) {
                for (int r = 0; r < rows; r++) {
                    if (index < textlen)
                        matrix[r][c] = ciphertext[index++];
                    else
                        matrix[r][c] = 'X';
                }
            }
        }
    }

    // Read row-wise
    index = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < keylen; c++) {
            output[index++] = matrix[r][c];
        }
    }

    output[index] = '\0';
}
