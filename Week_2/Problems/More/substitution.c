#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool check_key(string);
string cipher(string, string);

int main(int argc, string argv[])
{
    if (argc != 2 || check_key(argv[1]))
    {
        printf("Provide key (26 chars) as command line parameter.\n");
        return 1;
    }

    // Request plaintext string from user
    string plaintext = get_string("plaintext: ");

    // // Convert plaintext to ciphertext
    string ciphertext = cipher(plaintext, argv[1]);

    printf("ciphertext: %s\n", ciphertext);

    return 0;

}

bool check_key(string key)
{
    // Check if string is 26 characters in length
    if (strlen(key) != 26)
    {
        printf("Key is not 26 characters in length. ");
        return 1;
    }

    for (int i = 0; i < strlen(key); i++)
    {
        // Check if every character is alphabetical
        if (!isalpha(key[i]))
        {
            printf("Key contains non-alphabetical characters. ");
            return 1;
        }

        char c = tolower(key[i]);

        // Loop through the key to count the occurrences of the character
        int count = 0;
        for (int j = 0; j < strlen(key); j++)
        {
            if (c == tolower(key[j]))
            {
                count++;
            }
        }

        if (count > 1)
        {
            printf("Key contains repeating characters. ");
            return 1;
        }
    }

    return 0;
}

string cipher(string plaintext, string key)
{
    string ciphertext = plaintext;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // Only apply cipher to alphabetic characters
        if (isalpha(plaintext[i]))
        {
            int loc = tolower(plaintext[i]) - 97;

            // Apply the capitalization
            if (isupper(plaintext[i]))
            {
                ciphertext[i] = toupper(key[loc]);
            }
            else
            {
                ciphertext[i] = tolower(key[loc]);
            }
        }
    }

    return ciphertext;
}