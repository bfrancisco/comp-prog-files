n = int(input())
print(0 if (n%4==0 or n%4 == 3) else 1)
out = ['A']
n -= 1
x = 0
while n != 0:
    if x%4 < 2:
        out.append('B')
    else:
        out.append('A')
    x += 1
    n -= 1
for i in out[::-1]:
    print(i, end='')