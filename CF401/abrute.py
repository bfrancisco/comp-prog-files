n = int(input())
x = int(input())
while n:
    if n%2 and x != 2:
        x = (1 if x==0 else 0)
    elif n%2==0 and x != 0:
        x = (2 if x==1 else 1)
    n -= 1
print(x)