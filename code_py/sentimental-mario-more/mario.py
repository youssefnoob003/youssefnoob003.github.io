# TODO
from cs50 import get_int


def get_height():
    height = get_int("height: ")
    if height <= 0 or height >= 9:
        return get_height()
    return height


def pyramid():
    n = get_height()
    for i in range(1, n + 1):
        pyr = (n - i) * " " + "#" * i + "  " + "#" * i
        print(pyr)


pyramid()
