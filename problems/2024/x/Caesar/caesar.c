#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validate(string argv[]);

int main(int argc, string argv[])
{
    if (argc != 2 || !validate(argv))
    {
        printf("Usage: ./caesar KEY");
        return 1;
    }

    int key = atoi(argv[1]);


    const char alphaUpper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    const char alphaLower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string plaintext = get_string("Plaintext: ");
    string ciphertext = plaintext;

    for (int j = 0; j < strlen(plaintext); j++)
    {
        for (int k = 0; alphaUpper[k] != '\0'; k++)
        {
            int pos = (k + key) % 26;
            if (plaintext[j] == alphaUpper[k])
            {
                ciphertext[j] = alphaUpper[pos];
                break;
            }

            if (plaintext[j] == alphaLower[k])
            {
                ciphertext[j] = alphaLower[pos];
                break;
            }
        }
    }

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

bool validate(string argv[]) {
    for(int i = 0; i < strlen(argv[1]); i++ ) {
        if(!isdigit(argv[1][i])) {
            return false;
        }
    }
    return true;
}
