#include <ctype.h>
#include <string.h>
#include "beaufort.h"

void beaufort_cipher(const char *input, const char *key, char *result) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; input[i]; i++) {
        char ch = input[i];
        if (isalpha(ch)) {
            char k = tolower(key[j % keyLen]) - 'a';
            char base = isupper(ch) ? 'A' : 'a';
            int p = tolower(ch) - 'a';
            int c = (k - p + 26) % 26;
            result[i] = base + c;
            j++;
        } else {
            result[i] = ch;
        }
    }
    result[strlen(input)] = '\0';
}
