from cs50 import get_string
from sys import argv


def main():

    if not len(argv) == 2:
        print("Usage: python bleep.py dictionary")
        exit(1)
    else:
        banned_words = set()

        # open banned_words file to read
        with open(argv[1], "r") as f:
            # copy banned_words into the set
            for line in f:
                banned_words.add(line.strip())

        # prompt user for message
        message = get_string("What message would you like to check?\n")
        message_bleep = ""
        # split message to words
        message_words = message.split(" ")

        message_bleep = ""
        # censor banned words
        for word in message_words:
            if word.lower() in banned_words:
                message_bleep += ("*" * len(word)) + " "
# test                print(word)
            else:
                message_bleep += word + " "

        # print bleeped message
        print(message_bleep.strip(),"\n")



if __name__ == "__main__":
    main()
