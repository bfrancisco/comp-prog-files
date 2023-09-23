#!/usr/bin/env python3

# Warning: Please refrain from using global variables! Your solution will be checked
# by importing your function, not from the raw input/output.

from wordlist import Wordlist

# mapping of digit to possible letters
# e.g., keypad[2] returns all letters mapped to 2
keypad = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz'
}

words = Wordlist('EnglishWords.txt')

### DON'T TOUCH the code above

def numtoword():
    
    return

def predict(digits: str) -> set[str]:
    bank = set()

    def rb(s, i, digits):
        if len(s) == len(digits):
            if words.contains(s):
                bank.add(s)
            return

        for c in keypad[digits[i]]:
            if (words.contains_prefix(s+c)):
                rb(s + c, i+1, digits)

    rb("", 0, digits)

    return bank

### DON'T TOUCH the code below

if __name__ == '__main__':
    digits = input()
    words = predict(digits)
    if len(words) == 0:
        print('NONE')
    else:
        for word in words:
            print(word)