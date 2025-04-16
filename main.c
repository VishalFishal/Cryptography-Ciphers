#include <stdio.h>
#include <string.h>

#include "caesar.h"
#include "atbash.h"
#include "affine.h"
#include "vigenere.h"
#include "gronsfeld.h"
#include "beaufort.h"
#include "autokey.h"
#include "runningkey.h"
#include "hill.h"
#include "railfence.h"
#include "route.h"
#include "myszkowiski.h"

#define MAX_LEN 100

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    char text[MAX_LEN];
    char result[MAX_LEN];
    int key;
    char wkey[MAX_LEN];
    int cipher_choice, ed_choice;

    while (1) {
        printf("\n=== Cipher Tool ===\n");
        printf("Choose a cipher:\n");
        printf("0. Exit\n");
        printf("1. Caesar Cipher\n");
        printf("2. Atbash Cipher\n");
        printf("3. August Cipher\n");
        printf("4. Affine Cipher\n");
        printf("5. Vigenere Cipher\n");
        printf("6. Gronsfeld Cipher\n");
        printf("7. Beaufort Cipher\n");
        printf("8. Autokey Cipher\n");
        printf("9. Running Key Cipher\n");
        printf("10. Hill Cipher\n");
        printf("11. Railfence Cipher\n");
        printf("12. Route Cipher\n");
        printf("13. Myszkowiski Cipher\n");
        printf("Enter your choice: ");
        scanf("%d", &cipher_choice);
        getchar();  // flush newline

        if (cipher_choice == 0) {
            printf("Exiting.\n");
            break;
        }

        memset(result, 0, MAX_LEN);

        switch (cipher_choice) {
            case 1:  // Caesar
                printf("1. Encrypt\n2. Decrypt\nChoose: ");
                scanf("%d", &ed_choice);
                getchar();

                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';

                printf("Enter Caesar key (integer): ");
                scanf("%d", &key);

                if (ed_choice == 1) {
                    caesar_encrypt(text, key, result);
                    printf("Encrypted (Caesar): %s\n", result);
                } else if (ed_choice == 2) {
                    caesar_decrypt(text, key, result);
                    printf("Decrypted (Caesar): %s\n", result);
                } else 
                    printf("Invalid choice.\n");
                break;

            case 2:  // Atbash
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';

                atbash_cipher(text, result);
                printf("Output (Atbash): %s\n", result);
                break;

            case 3:  // August Cipher
                printf("1. Encrypt\n2. Decrypt\nChoose: ");
                scanf("%d", &ed_choice);
                getchar();
            
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                if (ed_choice == 1) {
                    caesar_encrypt(text, 1, result);
                    printf("Encrypted (August): %s\n", result);
                } else if (ed_choice == 2) {
                    caesar_decrypt(text, 1, result);
                    printf("Decrypted (August): %s\n", result);
                } else 
                    printf("Invalid choice.\n");
                break;
            
            case 4:  // Affine Cipher
                printf("1. Encrypt\n2. Decrypt\nChoose: ");
                scanf("%d", &ed_choice);
                getchar();
            
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                printf("Enter key a (must be coprime with 26): ");
                scanf("%d", &key);
                if (gcd(key, 26) != 1) {
                    printf("Error: 'a' must be coprime with 26.\n");
                    break;
                }

                printf("Enter key b (0-25): ");
                int b;
                scanf("%d", &b);
                if (b < 0 || b > 25) {
                    printf("Error: 'b' must be between 0 and 25.\n");
                    break;
                }
            
                if (ed_choice == 1) {
                    affine_encrypt(text, key, b, result);
                    printf("Encrypted (Affine): %s\n", result);
                } else if (ed_choice == 2) {
                    affine_decrypt(text, key, b, result);
                    printf("Decrypted (Affine): %s\n", result);
                } else 
                    printf("Invalid choice.\n");
                break;

            case 5:  // Vigenere Cipher
                printf("1. Encrypt\n2. Decrypt\nChoose: ");
                scanf("%d", &ed_choice);
                getchar();
            
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                printf("Enter keyword: ");
                fgets(wkey, MAX_LEN, stdin);
                wkey[strcspn(wkey, "\n")] = '\0';
            
                if (ed_choice == 1) {
                    vigenere_encrypt(text, wkey, result);
                    printf("Encrypted (Vigenere): %s\n", result);
                } else if (ed_choice == 2) {
                    vigenere_decrypt(text, wkey, result);
                    printf("Decrypted (Vigenere): %s\n", result);
                 } else 
                    printf("Invalid choice.\n");
                break;

            case 6: //Gronsfeld
                    printf("1. Encrypt\n2. Decrypt\nChoice: ");
                    scanf("%d", &ed_choice);
                    getchar();
                
                    printf("Enter text: ");
                    fgets(text, MAX_LEN, stdin);
                    text[strcspn(text, "\n")] = '\0';
                
                    printf("Enter numeric key (e.g., 31415): ");
                    fgets(wkey, sizeof(wkey), stdin);
                    wkey[strcspn(wkey, "\n")] = 0;
                
                    if (ed_choice == 1) {
                        gronsfeld_encrypt(text, wkey, result);
                        printf("Encrypted (Gronsfeld): %s\n", result);
                    } else if (ed_choice == 2) {
                        gronsfeld_decrypt(text, wkey, result);
                        printf("Decrypted (Gronsfeld): %s\n", result);
                     } else 
                        printf("Invalid choice.\n");
                    break;

            case 7:  // Beaufort Cipher
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                printf("Enter keyword: ");
                char bkey[MAX_LEN];
                fgets(bkey, MAX_LEN, stdin);
                bkey[strcspn(bkey, "\n")] = '\0';
            
                beaufort_cipher(text, bkey, result);
                printf("Output (Beaufort): %s\n", result);
                break;

            case 8:  // Autokey Cipher
                printf("1. Encrypt\n2. Decrypt\nChoice: ");
                scanf("%d", &ed_choice);
                getchar();

                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                printf("Enter key: ");
                fgets(wkey, MAX_LEN, stdin);
                wkey[strcspn(wkey, "\n")] = '\0';
            
                if (ed_choice == 1) {
                    autokey_encrypt(text, wkey, result);
                    printf("Encrypted (Autokey): %s\n", result);
                } else if (ed_choice == 2) {
                    autokey_decrypt(text, wkey, result);
                    printf("Decrypted (Autokey): %s\n", result);
                    } else 
                    printf("Invalid choice.\n");
                break;

            case 9:  // Running Key Cipher
                printf("1. Encrypt\n2. Decrypt\nChoose: ");
                scanf("%d", &ed_choice);
                getchar();
            
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                printf("Enter running key (must be at least as long as the text): ");
                fgets(wkey, MAX_LEN, stdin);
                wkey[strcspn(wkey, "\n")] = '\0';
            
                if (ed_choice == 1) {
                    running_key_encrypt(text, wkey, result);
                    printf("Encrypted (Running Key): %s\n", result);
                } else if (ed_choice == 2) {
                    running_key_decrypt(text, wkey, result);
                    printf("Decrypted (Running Key): %s\n", result);
                } else {
                    printf("Invalid choice.\n");
                }
                break;

            case 10: 
                    printf("1. Encrypt\n2. Decrypt\nChoose: ");
                    scanf("%d", &ed_choice);
                    getchar();
                
                    printf("Enter text: ");
                    fgets(text, MAX_LEN, stdin);
                    text[strcspn(text, "\n")] = '\0';
                
                    int key[2][2];
                    printf("Enter 2x2 Hill key matrix (row-wise): ");
                    scanf("%d %d %d %d", &key[0][0], &key[0][1], &key[1][0], &key[1][1]);
                    getchar();
                
                    if (ed_choice == 1) {
                        hill_encrypt(text, key, result);
                        printf("Encrypted (Hill): %s\n", result);
                    } else if (ed_choice == 2) {
                        if (!hill_decrypt(text, key, result))
                            printf("Invalid key matrix: no modular inverse exists.\n");
                        else
                            printf("Decrypted (Hill): %s\n", result);
                    } else {
                        printf("Invalid choice.\n");
                    }
                    break;

            case 11:  // Rail Fence Cipher
                printf("1. Encrypt\n2. Decrypt\nChoose: ");
                scanf("%d", &ed_choice);
                getchar();
            
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                printf("Enter number of rails (integer): ");
                int skey;
                scanf("%d", &skey);
                getchar();
            
                if (ed_choice == 1) {
                    railfence_encrypt(text, skey, result);
                    printf("Encrypted (Rail Fence): %s\n", result);
                } else if (ed_choice == 2) {
                    railfence_decrypt(text, skey, result);
                    printf("Decrypted (Rail Fence): %s\n", result);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            
            case 12:  // Route Cipher
                printf("1. Encrypt\n2. Decrypt\nChoose: ");
                scanf("%d", &ed_choice);
                getchar();
            
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                printf("Enter route key (number of columns): ");
                int sskey;
                scanf("%d", &skey);
                getchar();
            
                if (ed_choice == 1) {
                    routecipher_encrypt(text, sskey, result);
                    printf("Encrypted (Route): %s\n", result);
                } else if (ed_choice == 2) {
                    routecipher_decrypt(text, sskey, result);
                    printf("Decrypted (Route): %s\n", result);
                } else {
                    printf("Invalid choice.\n");
                }
                break;

            case 13:  // Myszkowski Cipher
                printf("1. Encrypt\n2. Decrypt\nChoose: ");
                scanf("%d", &ed_choice);
                getchar();
            
                printf("Enter text: ");
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = '\0';
            
                printf("Enter keyword: ");
                fgets(wkey, MAX_LEN, stdin);
                wkey[strcspn(wkey, "\n")] = '\0';
            
                if (ed_choice == 1) {
                    myszkowski_encrypt(text, wkey, result);
                    printf("Encrypted (Myszkowski): %s\n", result);
                } else if (ed_choice == 2) {
                    myszkowski_decrypt(text, wkey, result);
                    printf("Decrypted (Myszkowski): %s\n", result);
                } else {
                    printf("Invalid choice.\n");
                }
                break;
                    
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n============ OLD ITERATION ============\n");
    }

    return 0;
}
