#ifndef RAILFENCE_H
#define RAILFENCE_H

void railfence_encrypt(const char* plaintext, int rails, char* result);
void railfence_decrypt(const char* ciphertext, int rails, char* result);

#endif
