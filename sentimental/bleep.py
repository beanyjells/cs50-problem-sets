import sys
from cs50 import get_string
from sys import argv


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: python bleep.py dictionary")
        return 1
    else:
        infile = sys.argv[1]
        # initialise a dictionary set and add all the words from the inputted text file to it
        dictionary = set(open(infile).read().split())
        # prompt user to provide a message
        msg = get_string("What message would you like to censor? \n")
        msg_words = msg.split()  # splits up each word in the string into tokens
        new_msg = ""  # initialising a new string so we can print the censored sentence easily
        for word in msg_words:
            if word.lower() in dictionary:
                new_msg += ('*'*len(word)) + " "  # censors the bad word and adds it to the new string
            else:
                new_msg += word + " "  # leaves non-bad words the same and adds to new string
        print(new_msg)


if __name__ == "__main__":
    main()