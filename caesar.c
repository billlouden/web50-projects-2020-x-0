#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //checking the two inputs ha
    if (argc == 2)
    {
        int n = strlen(argv[1]);
        int i;
        for (i = 0; i < n; i++) 
        {
            //checking argv[1] for any alphabetic characters present, if so                  returning the error message
            if (isalpha(argv[1][i]))    
            {
                printf("Enter key as a positive number\n");
                return 1;    
            }
            //checking argv[1] for all decimal digits before converting the                 string to an interger
            else if (isdigit(argv[1][i]))
            {
                //this turns the key into an int variable
                int key = atoi(argv[1]);
                //requests the message to be coded, from the user
                string plaintext = get_string("Enter message: ");
                printf("ciphertext: ");
                for (int b = 0, c = strlen(plaintext); b < c; b++)
                {
                    //checks if the character is upper case and if so encrypts it in upper case
                    if (isupper(plaintext[b]))
                    {
                        printf("%c", (((plaintext[b] + key) - 65) % 26) + 65);
                    }
                    //checks if character is lower case and if so encrypts it in lower case
                    else if (islower(plaintext[b]))
                    {    
                        printf("%c", (((plaintext[b] + key) - 97) % 26) + 97);
                    }
                    //if chracter is not upper or lower case, e.g. a question mark, it prints as a question mark
                    else
                    {
                        printf("%c", plaintext[b]);
                    }
                }
                printf("\n");
                return 0;
            }
        }
    }
    //if argc doesn't equal 2, printing error message back to user
    else
    {
        printf("Enter one key\n");
        return 1;
    }
}
