n = int(input())
for i in range(n):
    wine = input()
    num = float(wine[:-1])
    for digit in str(num):
        if digit == '.':
            continue
        print(chr(int(digit)+97), end = '')
    print()

# print(ord('a'))