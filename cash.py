# calculate number of coins to return
# Bill Louden
# CS50

import cs50


def main():
    while True:
        print("Change owed?")
        amount = cs50.get_float("Change owed: ")
        # don't allow negative numbers
        if amount >= 0:
            break
    # set coins to 0 and round any fractions
    coins = 0
    cents = int(round(amount * 100))
    # determine number of quarters then increment coins counter
    coins += cents // 25
    cents %= 25

    # determine number of dimes from remainder then increment coins counter
    coins += cents // 10
    cents %= 10

    # determine number of nickles from remainder then increment coins counter
    coins += cents // 5
    cents %= 5
    # determine number of pennies from remainder then increment coins counter
    coins += cents

    print(coins)


if __name__ == "__main__":
    main()