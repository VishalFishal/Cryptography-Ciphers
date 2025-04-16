#ifndef GRONSFELD_H
#define GRONSFELD_H

void gronsfeld_encrypt(const char *plaintext, const char *key, char *result);
void gronsfeld_decrypt(const char *ciphertext, const char *key, char *result);

#endif
