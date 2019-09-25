#include <stdio.h>
#include <math.h>
#include <cs50.h>
// re-submission following instructions with no
// extraneous information.
// compacted code to minimum
int main()
{
    int cents;    // we will convert dollars into cents

    do
    {
        // get a floating point number
        float dollars = get_float("Change owed: ");
        // round to a positive value
        cents = round(dollars * 100);
    }

    while (cents <= 0);
    // how many quarters can be made
    int quarters = cents / 25;
    // how many dimes can be made
    int dimes = (cents % 25) / 10;
    // how many nickels can be made
    int nickels = ((cents % 25) % 10) / 5;
    // how many pennies can be made
    int pennies = ((cents % 25) % 10) % 5;
    // print sum
    printf("%d\n", quarters + dimes + nickels + pennies);
}
