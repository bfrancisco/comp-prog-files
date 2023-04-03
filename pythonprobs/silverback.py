# needs concrete observations to understand this!
x = int(input())
if x < 8:
    print("NO")
elif x % 2 == 0:
    print("YES")
    print(4, x-4)
elif x < 12:
    print("NO")
elif x % 3 == 0:
    print("YES")
    print(9, x-9)
elif x % 5 == 0:
    print("YES")
    print(10, x-10)
else:
    print("YES")
    print(9, x-9)