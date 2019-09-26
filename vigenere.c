#import <stdio.h>
#import <cs50.h>
#import <string.h>
#include <ctype.h>

// function call
string cipher(string plain, string key);

int main(int argc, string argv[])
{   
    // convert argv[1] to variable key
    string key = argv[1];
    // Error if not 2 parameters (./vigenere, + the key)
    // return 1 so program exits
    if (argc != 2) {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    
    // loop through all the keysand check if alphabetical
    for(int i = 0, j = strlen(key); i < j; i++)
    {
        if (!isalpha(key[i]))
        {   
            printf("Usage: ./vigenere keyword\n");
            // cannot use non-alphabetical characters
            return 1;
        }
    }
    
    string plaintext;
    
    do {
        plaintext = get_string("Message: ");
    }
    while (strlen(plaintext) == 0);
    // keep asking for input until user enters at least 1 char
    
    // cipher plaintext
    string result = cipher(plaintext, key);
    
    // print the result back to the user
    printf("%s", "ciphertext: ");
    printf("%s\n", result);
    
    return 0;
}

// function called
string cipher(string plain, string key)
{
    // calculate length of key used later
    // define it here so strlen() so not part of loop
    int length = strlen(key);
    
    // initialize a variable that will hold cipher,
    // same length as plain string
    char *cipher = plain;
    
    // loop through all characters of the plain text string
    for (int i = 0, j = 0, n = strlen(plain); i < n; i++)
    {   
        // if alphabetic proceed with ciphering,
        // else return normal printable character
        if (isalpha(plain[i]))
        {
        // calculate ASCII code for the key position (j),
        // wrap around beginning of keyword when at end of keyword
        char ref = (isupper(key[j % length])) ? 'A' : 'a';
           
        // calculate ASCII code of the first letter of alphabet
        char value = (isupper(plain[i])) ? 'A' : 'a';
            
            // calculate cipher letter using formula ci = (pi + kj) % 26
            // then convert to right ASCII character number
            cipher[i] = ((plain[i] - value + (key[(j % length)] - ref)) % 26) + value;
            
            // increment key position (j) so next letter in key is used
            j++;
        }
        else
            {
            // output all non-alphabetical chars normally
            cipher[i] = plain[i];
            }
    }
    
    // return ciphered string
    return cipher;
}
