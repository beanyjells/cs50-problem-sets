from cs50 import get_float


def main():
    change = get_correct_input("Change owed: ")  # prompts function that ensures that a non-negative value is inputted by the user
    coins = 0  # to keep track of the number of coins
    remain = round(change*100)  # to keep track of the remainder after it's been rounded up
    if remain > 25:  # checking number of quarters
        coins = remain // 25  # integer dividing to find the number of quarters to give as change
        remain = remain % 25  # remainder after dividing by 25
    if remain > 10:  # checking number of dimes
        coins = coins + (remain // 10)  # integer dividing to find the number of dimes to give as change
        remain = remain % 10  # remainder after dividing by 10
    if remain > 5:  # checking number of nickels
        coins = coins + (remain // 5)  # integer dividing to find the number of nickels to give as change
        remain = remain % 5  # remainder after dividing by 5
    else:  # checking number of pennies
        coins = coins + (remain // 1)  # integer dividing to find the number of pennies to give as change
        remain = remain % 1  # remainder after dividing by 1 - should be 0 at this point
    print(coins)


def get_correct_input(prompt):
    # loop until we get a non-negative value from the user
    while True:
        c = get_float(prompt)
        if c > 0:
            break
    return c


if __name__ == "__main__":
    main()