#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

string convertToUpperCase(string text);
string convertToLowerCase(string text);

int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./caesar KEY");
        return 1;
    }

    int key = atoi(argv[1]);

    const char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    const size_t alphaSize = sizeof(alpha) / sizeof(alpha[0]);

    string plaintext = get_string("Plaintext: ");
    char ciphertext[] = {};

    string plaintext_copy = convertToUpperCase(plaintext);

    for(int j = 0; j < strlen(plaintext_copy); j++) {
        for(int k = 0; k < alphaSize; k++) {
            if(plaintext_copy[j] == alpha[k]) {
                int pos = (k+key)%26;
                ciphertext[j] = alpha[pos];
            }
        }
    }

    plaintext_copy = convertToLowerCase(plaintext_copy);

    printf("\nPlaintext: %s\n", plaintext_copy);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

string convertToUpperCase(string text) {
    int i = 0;
    while(text[i] != '\0') {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            i++;
            continue;
        }

        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] = toupper(text[i]);
            //text[i] ^= 32;
        }
        i++;
    }
    return text;
}

string convertToLowerCase(string text) {
    int i = 1;
    while(text[i] != '\0') {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = tolower(text[i]);
        }
        i++;
    }
    return text;
}
