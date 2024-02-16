def canBe(pizza, freqt, tops):
    f = {}
    for e in pizza:
        if e not in f:
            f[e] = 1
        else:
            f[e] += 1
    for t in tops:
        if t not in f or freqt[t] != f[t]:
            return False
    return True

def isMatch(A, B):
    for k in range(n+1):
        if A==B:
            return True
        B.rotate()
    return False

from collections import deque
for _ in range(int(input())):
    s, n = map(int, input().split())
    tops = [int(i) for i in input().split()]
    freqt = {}
    for t in tops:
        if t not in freqt:
            freqt[t] = 1
        else:
            freqt[t] += 1

    pizzas = []
    for i in range(s):
        pizza = [int(i) for i in input().split()]
        pizzas.append(deque(pizza))

    for i in range(s):
        if not canBe(pizzas[i], freqt, tops):
            continue
        good = True
        for j in range(s):
            if i==j: continue
            if isMatch(pizzas[i], pizzas[j]):
                good = False
                break
        if good:
            print(i+1)
            break
