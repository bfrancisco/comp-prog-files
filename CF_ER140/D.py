n = int(input())
s = input()

low = 1
high = 2**n
ad = 0
mi = 0
for i in s:
    if i == '1':
        low += 2**ad
        ad += 1
    else:
        high -= 2**mi
        mi += 1
for i in range(low, high+1):
    print(i, end=' ')
