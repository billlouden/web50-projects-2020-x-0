# Prints a staircase of 1 to 8 bricks

from cs50 import get_int

# Prompt user for a positive height

height = get_int("Height: ")

if height < 1 or height > 8:
    print("Enter Height value between 1 and 8")

else:

    for i in range(height):
        print(" " * (height - (i+1)) + "#" * (i + 1))
print()
