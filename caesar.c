#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Building a Caesar cipher - 3rd time the charm
// only do what instructor wants
int main(int argc, string argv[])
    
{
    //get key as a string
    string key  = argv[1];
    // ensure some argument is entered on command line
    // must be 2 -- the command + the key
    if (argc != 2)
    {
        // printf("Invalid key\n");
        return 1;
    }

    // convert string to an integer
    int k = atoi(argv[1]);
    // error if integer is <= zero
    if (k <= 0)
    {
        printf("Enter a numeric key\n");
        return 1;
    }
    else
    {
        // Sucessful key entered
        // Prompt user for message to encrypt
        string plaintext = get_string("Enter your Message\n");
        printf("ciphertext: ");    
        // iterate through characters up to length of string
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
        
            if islower(plaintext[i])            // check for lowercase
                // get integer at [i] subtract "a" get remainer add k

                printf("%c", (((plaintext[i] + k) - 97) % 26) + 97);

            else if (isupper(plaintext[i]))    // check for uppercase
                // get integer at [i] subtract "a" add k

                printf("%c", (((plaintext[i] + k) - 65) % 26) + 65);

            else
         
                printf("%c", plaintext[i]);

            }      
            return 0;
            printf("\n");
            
        }
        
    } 

