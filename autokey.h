#ifndef AUTOKEY_H
#define AUTOKEY_H

void autokey_encrypt(const char *text, const char *key, char *output);
void autokey_decrypt(const char *ciphertext, const char *key, char *plaintext);

#endif
