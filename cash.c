#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    int cents;

    do
    {
        float dollars = get_float("Change owed: ");
    if (dollars >999999)
            printf("I can't count that high\n");
    else
        cents = round(dollars * 100);
    }
    while (cents <= 0);
    int dollars = cents / 100;
    int quarters = (cents % 100 / 25);
    int dimes = (cents % 25) / 10;
    int nickels = ((cents % 25) % 10) / 5;
    int pennies = ((cents % 25) % 10) % 5;
    printf("dollars  :$");
    printf("%d\n",dollars);
    printf("quarters :");
    printf ("%d\n", quarters);
    printf("dimes    :");
    printf("%d\n", dimes);
    printf("nickels  :");
    printf("%d\n", nickels);
    printf("pennies  :");
    printf("%d\n", pennies);           
    //"+ dimes + nickels + pennies);
}
