#include<stdio.h>
#include<cs50.h>
int main (void)
{
    int height;
     int count = 0;
do
{
    height = get_int("Enter a number 1-8 for steps for Mario to climb: ");
}
while (height < 1 || height > 8);

    for(int i = height; i > 0; i--)               
    {
        for(int j = 0; j < i - 1; j++)                  
        {
            printf(" ");
        }
        printf("#");
        count++;
        for (int num = 1; num < count; num++)
        {
            printf("#");
        }
        printf("\n");
    }
}
