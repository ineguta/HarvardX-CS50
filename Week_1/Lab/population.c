#include <cs50.h>
#include <stdio.h>

int start_size(void);
int end_size(int);

int main(void)
{
    int start_n = start_size();
    int end_n = end_size(start_n);

    int i = 0;
    while (start_n < end_n)
    {
        start_n = start_n + (start_n / 3) - (start_n / 4);
        i++;
    }

    printf("Years: %i\n", i);
}


int start_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;
}

int end_size(int start)
{
    int n;
    do
    {
        n = get_int("End Size: ");
    }
    while (n < start);
    return n;
}