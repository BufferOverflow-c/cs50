#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substitution(string text, char subAlpha[]);
void cipher(string plaintext, string ciphertext, const char alphabet[], char subAlpha[]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }

    string text = argv[1];

    const char alphabet[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                                'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char subAlpha[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string plaintext = get_string("Plaintext: ");
    string ciphertext = plaintext;

    substitution(text, subAlpha);
    cipher(plaintext, ciphertext, alphabet, subAlpha);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

void substitution(string text, char subAlpha[]) {
    int i = 0;
    while(text[i] != '\0') {
        subAlpha[i] = text[i];
        i++;
    };

    for(int j = 0; text[j] != '\0'; j++) {
        text[j] ^= 32;
        subAlpha[i] = text[j];
        i++;
    }
}

void cipher(string plaintext, string ciphertext, const char alphabet[], char subAlpha[]) {
    for (int j = 0; j < strlen(plaintext); j++) {
        for (int k = 0; alphabet[k] != '\0'; k++) {
            if (plaintext[j] == alphabet[k]) {
                ciphertext[j] = subAlpha[k];
                break;
            }
        }
    }
}
