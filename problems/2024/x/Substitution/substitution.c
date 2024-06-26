#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validate(int argc, string argv[]);

int main(int argc, string argv[])
{
    if (!validate(argc, argv))
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }

    string key = argv[1];

    for(int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    const char alphabet[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                               'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                               'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    char subAlphabet[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string plaintext = get_string("Plaintext: ");
    string ciphertext = plaintext;

    for (int i = 0; i < 52; i++)
    {
        while (i < 26)
        {
            subAlphabet[i] = key[i];
            i++;
        }
        subAlphabet[i] = (key[i - 26] ^= 32);
    }

    for (int i = 0; i < strlen(plaintext); i++)
    {
        for (int j = 0; alphabet[j] != '\0'; j++)
        {
            if (plaintext[i] != alphabet[j])
            {
                continue;
            }
            ciphertext[i] = subAlphabet[j];
            break;
        }
    }

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

bool validate(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution KEY");
        return false;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if ((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
        {
            continue;
        }
        printf("Usage: ./substitution KEY");
        return false;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Usage: ./substitute KEY");
                return false;
            }
        }
    }

    return true;
}
