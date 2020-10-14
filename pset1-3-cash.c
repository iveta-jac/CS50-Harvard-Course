#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int cents, change, q, d, n, p;
    do
    {
        // User inputs how much change is owed
        dollars = get_float("Change: ");
    }
    while (dollars < 0);

    // Round dollars to cents
    cents = round(dollars * 100);

    // Priority is to use the largest coins possible
    q = cents / 25;
    d = cents % 25 / 10;
    n = cents % 25 % 10 / 5;
    p = cents % 25 % 10 % 5 / 1;

    // Minimum number of coins with which change can be made
    change = q + d + n + p;
    printf("%i\n", change);
}
