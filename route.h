#ifndef ROUTE_H
#define ROUTE_H

void routecipher_encrypt(const char *plaintext, int key, char *output);
void routecipher_decrypt(const char *ciphertext, int key, char *output);

#endif
