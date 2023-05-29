# TODO
from cs50 import get_int


def valid(n):
    res = 0
    for i in range(len(n) - 2, -1, -2):
        res += sum(str(int(n[i]) * 2)) + int(n[i + 1])
    print(res)
    if res % 10 == 0:
        return True
    return False


def sum(x):
    res = 0
    for i in x:
        res += int(i)
    return res


def type(n):
    if not valid:
        return "INVALID"
    if n[0:2] in ["51", "52", "53", "54", "55"]:
        return "MASTERCARD"
    if n[0:2] in ["34", "37"]:
        return "AMEX"
    if n[0] == "4":
        return "VISA"
    return "INVALID"


def main():
    card_number = get_int("Number: ")
    card_number = str(card_number)
    print(type(card_number))


main()
