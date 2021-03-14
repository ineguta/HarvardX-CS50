#include <cs50.h>
#include <stdio.h>
#include <math.h>

int cash(void);

int main(void)
{
    int change = cash();

    int i = change / 25;
    change = change - (25 * (change / 25));

    i += change / 10;
    change = change - (10 * (change / 10));

    i += change / 5;
    change = change - (5 * (change / 5));

    i += change;

    printf("%i\n", i);
}

int cash(void)
{
    // Request height value from user
    int n;
    do
    {
        n = round(100 * get_float("Change owed: "));
    }
    while (n < 1);

    return n;
}