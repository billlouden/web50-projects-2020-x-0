# cash.py
# Bill Louden
# Program to convert dollars into cents
#

from cs50 import get_float


def main():
    money = get_float("Change owed: ")

    while (money < 0):
        money = get_float("Change: ")
        break

    cents = round(money * 100)
#   print (cents)
    quarters = int(cents / 25)
#   print(quarters)
    dimes = int(quarters % 10)
#   print(dimes)
    nickles = int(dimes % 5)
#   print(nickles)
    pennies = int(cents % 25 % 10 % 5)
#   print(pennies)

    print(quarters+dimes+nickles+pennies)


if __name__ == "__main__":
    main()