#include <cs50.h>
#include <stdio.h>
#include <math.h>


int digit_sum(int);
int first_digits(long);
void supplier(int);

int main(void)
{
    long cc_num = get_long("Number: ");

    if (cc_num > pow(10, 12))
    {
        int first_two = first_digits(cc_num);

        int i, j = 0;

        for (i = 0; cc_num > 0; i++)
        {
            // Iterate through the card numbers backwards
            int rem = cc_num % 10;
            cc_num = cc_num / 10;

            if (0 == i % 2)
            {
                j += rem;
            }
            else
            {
                j += digit_sum(rem);
            }
        }

        if (0 != j % 10)
        {
            printf("INVALID\n");
        }
        else
        {
            supplier(first_two);
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


int digit_sum(int num)
{
    // Sum the individual digits according to Luhn’s Algorithm
    num = 2 * num;
    if (num > 9)
    {
        int rem = 0;
        do
        {
            rem += num % 10;
            num = num / 10;
        }
        while (num > 0);
        num = rem;
    }

    return num;
}

int first_digits(long num)
{
    while (num > 99)
    {
        num /= 10;
    }

    return (int) num;
}

void supplier(int num)
{
    // Check the starting digits to identify supplier
    switch (num)
    {
        case 34:
        case 37:
            printf("AMEX\n");
            break;
        case 51 ... 55:
            printf("MASTERCARD\n");
            break;
        case 40 ... 49:
            printf("VISA\n");
            break;
        default:
            printf("INVALID\n");
    }
}