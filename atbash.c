#include <ctype.h>
#include "atbash.h"

//symmetrical cipher
void atbash_cipher(const char *input, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (isupper(ch)) {
            output[i] = 'Z' - (ch - 'A');
        } else if (islower(ch)) {
            output[i] = 'z' - (ch - 'a');
        } else {
            output[i] = ch;
        }
    }
}
