#include <cs50.h>
#include <stdio.h>

int height(void);
void insert_hash(int);

int main(void)
{
    int n = height();

    for (int i = 1; i <= n; i++)
    {
        // Insert the spaces (max height - row number)
        for (int j = n; j > i; j--)
        {
            printf(" ");
        }

        // Insert the hashes
        insert_hash(i);

        printf("  ");

        insert_hash(i);

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

void insert_hash(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}