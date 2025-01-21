db = "abcdefghijklmnopqrstuvwxyz_.?!-,"
for _ in range(int(input())):
    M, x, y, z = map(int, input().split())
    m = x^y^z
    s = bin(m)[2:]

    if len(s) % (M*5):
        s = '0'*((M*5)-(len(s)%(M*5))) + s

    for i in range(0, M*5, 5):
        print(db[int(s[i:i+5], 2)], end='')
    print()