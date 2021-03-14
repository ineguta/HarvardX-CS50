#include <cs50.h>
#include <stdio.h>

int height(void);

int main(void)
{
    int n = height();

    for (int i = 1; i <= n; i++)
    {
        // Insert the spaces (max height - row number)
        for (int k = n; k > i; k--)
        {
            printf(" ");
        }

        // Insert the hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int height(void)
{
    // Request height value from user
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    return n;
}

