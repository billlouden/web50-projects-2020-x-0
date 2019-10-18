# Prints a staircase of 1 to 8 bricks
# Bill Louden

from cs50 import get_int

# Prompt user for a positive height


def main():
    height = get_int("Height: ")

    while (height < 1 or height > 8):
        # set height to new height
        height = get_int("Height: ")
        # if within range, print padded spaces of height - count + 1, then print hash
    if height >= 1 or height <= 8:
        for count in range(height):
            print(" " * (height - (count + 1)) + "#" * (count + 1))


print()

if __name__ == "__main__":
    main()