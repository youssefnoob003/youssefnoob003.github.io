# TODO
from cs50 import get_string


def letters(text):
    res = 0
    for i in text:
        if "a" <= i.lower() <= "z":
            res += 1
    return (res / words(text)) * 100


def sentences(text):
    res = 0
    for i in text:
        if i in [".", "!", "?"]:
            res += 1
    return (res / words(text)) * 100


def words(text):
    res = 0
    for i in text:
        if i == " ":
            res += 1
    return res + 1


def main():
    text = get_string("text: ")
    index = round(0.0588 * letters(text) - 0.296 * sentences(text) - 15.8)
    if index < 1:
        print(" Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


main()