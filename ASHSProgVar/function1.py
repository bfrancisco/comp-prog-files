def print10times(word):
    # it will take a string input,
    # then print it 10 times
    print(word)
    print(word)
    print(word)
    print(word)
    print(word)
    print(word)
    print(word)
    print(word)
    print(word)
    print(word)

def print_nth_lowest(a, n):
    a.sort()
    return a[n-1]


a = [6, 1, 2, 3, 5, 4]

# get minimum and maximum value
# min_value = min(a)
# max_value = max(a)

# print the last number
# print(a[-1])

# take a string input and print it 10 times
# word = input()
# print10times(word)

# print the n-th lowest number
nlowest = print_nth_lowest(a, 5)
print(nlowest)
