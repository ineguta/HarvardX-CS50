#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool check_param(string);
string cipher(string, int);
char convert_char(int, int);

int main(int argc, string argv[])
{
    if (argc != 2 || !check_param(argv[1]))
    {
        printf("Provide 1 integer command line parameter. Eg %s 10\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]) % 26;

    // Request plaintext string from user
    string plaintext = get_string("plaintext: ");

    // Convert plaintext to ciphertext
    string ciphertext = cipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);

    return 0;

}

bool check_param(string param)
{
    // Returns true if param is allowed (digits only)
    for (int i = 0; i < strlen(param); i++)
    {
        if (!isdigit(param[i]))
        {
            return false;
        }
    }

    return true;
}

string cipher(string plaintext, int key)
{
    // Function to turn plaintext into ciphertext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        plaintext[i] = convert_char(plaintext[i], key);
    }

    return plaintext;
}

char convert_char(int c, int key)
{
    // Function to move a character by a key value
    if (islower(c))
    {
        c = c + key;
        if (c > 122)
        {
            c = c - 26;
        }
    }
    else if (isupper(c))
    {
        c = c + key;
        if (c > 90)
        {
            c = c - 26;
        }
    }

    return c;
}