#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Building a Caesar cipher
int main(int argc, string argv[])
    
{
    //get key as a string
    string key  = argv[1];
    // ensure some argument is entered on command line
    // must be 2 -- the command + the key
    if (argc != 2)
    {
        printf("Invalid key\n");
        return 1;
    }

    {
        // convert string to an integer
        int k = atoi(argv[1]);
        // error if integer is zero
        if (k == 0)
            
        {
            printf("Enter a numeric key\n");
            return 1;
        }

        // Sucessful key entered
        // Prompt user for message to encrypt
        string plaintext = get_string("Enter your Message\n");
        // iterate through characters up to length of string
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int ch = 0;
            // check for uppercase
            if (isupper(plaintext[i]))
            {
                // get integer at [i] subtract ASCII "A" add k
                ch = (((int) plaintext[i] - 65 + k) % 26) + 65;
                printf("%c", (char) ch);
            }
            else if (islower(plaintext[i]))
            {
                // get integer at [i] subtract ASCII "a" add k
                ch = (((int) plaintext[i] - 97 + k) % 26) + 97;
                printf("%c", (char) ch);
            }
            else
            {
                //print other characters as-is
                printf("%c", plaintext[i]);
            }
        }
        //end of cypher, print new line
        printf("\n");
        return 0;
    }
} 

