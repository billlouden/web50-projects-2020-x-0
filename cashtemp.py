# cash.py
# Bill Louden
# Program to convert dollars into cents
#

import cs50


def main():

    while True:
        print("Change owed: ")
        money = cs50.get_float("Change owed: ")
        if amount >= 0:
            break
    print(money)
    coins = 0
    cents = int(round(money * 100))

    coins += cents // 25
    cents %= 25
    dimes = (cents % 25) // 10
    nickles = (cents % 25 // 5)
    pennies = (cents % 25) %10 %5

    print(quarters+dimes_nickles+pennies)


if __name__ == "__main__":
    main()