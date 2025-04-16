#include <string.h>
#include <stdlib.h>
#include "railfence.h"

void railfence_encrypt(const char* plaintext, int rails, char* result) {
    int len = strlen(plaintext);
    if (rails <= 1 || rails >= len) {
        strcpy(result, plaintext);
        return;
    }

    int index = 0;
    for (int r = 0; r < rails; r++) {
        int step = 2 * (rails - 1);
        for (int i = r; i < len; ) {
            result[index++] = plaintext[i];
            if (r != 0 && r != rails - 1) {
                int mid = i + step - 2 * r;
                if (mid < len)
                    result[index++] = plaintext[mid];
            }
            i += step;
        }
    }
    result[index] = '\0';
}

void railfence_decrypt(const char* ciphertext, int rails, char* result) {
    int len = strlen(ciphertext);
    if (rails <= 1 || rails >= len) {
        strcpy(result, ciphertext);
        return;
    }

    char* mark = (char*)malloc(len);
    memset(mark, 0, len);

    int idx = 0;
    for (int r = 0; r < rails; r++) {
        int step = 2 * (rails - 1);
        for (int i = r; i < len; ) {
            if (!mark[i]) {
                mark[i] = 1;
                idx++;
            }
            if (r != 0 && r != rails - 1) {
                int mid = i + step - 2 * r;
                if (mid < len && !mark[mid]) {
                    mark[mid] = 1;
                    idx++;
                }
            }
            i += step;
        }
    }

    char* temp = (char*)malloc(len);
    memcpy(temp, ciphertext, len);

    idx = 0;
    for (int r = 0; r < rails; r++) {
        int step = 2 * (rails - 1);
        for (int i = r; i < len; ) {
            if (mark[i]) {
                result[i] = temp[idx++];
                mark[i] = 0;
            }
            if (r != 0 && r != rails - 1) {
                int mid = i + step - 2 * r;
                if (mid < len && mark[mid]) {
                    result[mid] = temp[idx++];
                    mark[mid] = 0;
                }
            }
            i += step;
        }
    }

    result[len] = '\0';
    free(mark);
    free(temp);
}
