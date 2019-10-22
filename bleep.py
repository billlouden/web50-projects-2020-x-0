from cs50 import get_string
from sys import argv


def main():


    for arg in argv[1:]:
        try:
        # Get user input from command line
            print("Enter filename of banned words '*.txt: '")
            f = open(arg, 'r')
        except OSError:
            print('cannot find file', arg)
            exit(1)
        else:
#           print("got file")
            # create a set
            banned_words = set(argv[1])

        # open banned_words file to read
        with open(argv[1], "r") as f:
            # copy banned_words to the set
            for line in f:
                banned_words.add(line.strip())

        # prompt user for message
        message = get_string("What message would you like to bleep?\n")
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
        print(message_bleep.strip())



if __name__ == "__main__":
    main()
