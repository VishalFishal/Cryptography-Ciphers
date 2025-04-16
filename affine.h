#ifndef AFFINE_H
#define AFFINE_H

void affine_encrypt(const char* input, int a, int b, char* result);
void affine_decrypt(const char* input, int a, int b, char* result);
int mod_inverse(int a, int m);

#endif
