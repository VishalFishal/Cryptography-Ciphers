#ifndef HILL_H
#define HILL_H

void hill_encrypt(const char* plaintext, int key[2][2], char* output);
int hill_decrypt(const char* ciphertext, int key[2][2], char* output);

#endif
