
n = int(input())
for i in range(1, 100):
    a = int(('7'*i))
    if a % n == 0:
        print(a, len((str(a))))
        break