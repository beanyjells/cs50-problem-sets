#!/usr/bin/python3

import sys

from cs50 import get_string


def main():
    correct_arguments()  # making sure that only one command-line argument is inputted by the user
    key = int(sys.argv[1])  # converting digit string to an integer called key
    if (key < 0):  # making sure the key is positive
        print("Usage: python caesar.py key \n")
        return 1

    # after validity has been checked
    else:
        # prompt user to input plaintext
        plain = get_string("plaintext: ")
        len_plain = len(plain)

        # convert plaintext to ciphertext using inputted key
        cipher = plain  # ensures non-alphabetic characters remain the same
        print("ciphertext: ", end='')
        for x in range(len_plain):
            if plain[x] >= 'a' and plain[x] <= 'z':
                # convert the value of the character in the plaintext string to the ascii value and add the cipher key
                newvalue = (ord(plain[x]) + key) % 122
                # replace the old value of the string with the enciphered value
                cipher = cipher.replace(cipher[x], chr(newvalue))
                if newvalue < 97:  # to enable wraparound of alphabetic values
                    newvalue = newvalue + 96
                    cipher = cipher.replace(cipher[x], chr(newvalue))
            elif plain[x] >= 'A' and plain[x] <= 'Z':
                newvalue = (ord(plain[x]) + key) % 90
                cipher = cipher.replace(cipher[x], chr(newvalue))
                if newvalue < 65:
                    newvalue = newvalue + 64
                    cipher = cipher.replace(cipher[x], chr(newvalue))
            print(cipher[x], end="")

        print()


def correct_arguments():  # function that checks the inputted command line arguments
    if len(sys.argv) != 2:
        print("Usage: python caesar.py k \n")
        exit(1)


if __name__ == "__main__":
    main()