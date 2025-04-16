#ifndef RUNNINGKEY_H
#define RUNNINGKEY_H

void running_key_encrypt(const char* plaintext, const char* key, char* output);
void running_key_decrypt(const char* ciphertext, const char* key, char* output);

#endif
