from math import sqrt
import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    db = {}
    for x in a:
        if x not in db:
            db[x] = 1
        else:
            db[x] += 1


    # x^2 - bx + c
    for z in range(int(input())):
        b, c = map(int, input().split())
        D = b*b - 4*c
        if (D < 0):
            print(0, end=' ')
            continue
        r1, r2 = (b - sqrt(D)) / 2, (b + sqrt(D)) / 2
        if r1 in db and r2 in db:
            if r1 == r2:
                print(db[r1]*(db[r1]-1)//2, end=' ')
            else:
                print(db[r1]*db[r2], end=' ')
        else:
            print(0, end=' ')
    print()
