#ifndef VIGENERE_H
#define VIGENERE_H

void vigenere_encrypt(const char* plaintext, const char* key, char* result);
void vigenere_decrypt(const char* ciphertext, const char* key, char* result);

#endif