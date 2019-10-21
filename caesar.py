# caesar.py
# this is a recreation of my earlier C program.
# Bill Louden 2019
#
# Supports command line cipher code. Usage:  python caesar.py <numeric>
#
# import sys
from sys import argv
from cs50 import get_string


def main():
    # get user input from argv[]
    # input validity check of argv[1]
    # if I don't have a numeric...

    if len(argv) != 2 or argv[1] = "\0":
        print("Usage: python caesar <number>")
        exit 1

    # DONE use code to shift plain text
    code = int(argv[1])

    # DONE get plain text
    # Get text to convert
    plaintext = get_string("Plaintext: ")

    # prompt to queue up forthcoming ciphertext
    print("ciphertext: ", end="")

    # DONE  Convert to cipher text
    # do the conversion
    # for each char in plaintext check to see if it is an alpha character
    # if not alpha, just print char
    for char in plaintext:
        if not char.isalpha():
            print(char, end="")
            continue

        # set index to ascii 65 if char is upper case, set to 97 if char is lowercase
        index = 65 if char.isupper() else 97

        # ord function returns ascii value of char so we can do the math
        p = ord(char) - index
        # chr function returns the ascii char

        # we also do a modulo 26 to use alpha index
        char = (p + code) % 26

        # TODO  Print cipher text
        print(chr(char + index), end="")
    # print new line
    print()
    return 0


if __name__ == "__main__":
    main()