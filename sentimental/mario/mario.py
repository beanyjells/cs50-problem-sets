from cs50 import get_int


def main():
    height = get_correct_height("Height: ")  # Prompts function to ensure user inputs a number within the range we want
    for i in range(height):
        for j in range(height):
            if j >= (height-1-i):
                print("#", end="")  # to print '#' at the end of the block
            else:
                print(" ", end="")  # to print ' ' in the beginnin
        print()  # to create a line break


def get_correct_height(prompt):

    # loop until we get an input within the desired range
    while True:
        h = get_int(prompt)
        # make sure height is between 1 and 8
        if h > 0 and h < 9:
            break
    return h


if __name__ == "__main__":
    main()