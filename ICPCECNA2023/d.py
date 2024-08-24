V = [int(i) for i in input().split()]
x, kwf = map(int, input().split())

sm = 0
for i in range(0, 10, 2):
    a, b = V[i], V[i+1]
    sm += a*b

print(sm//5*x//kwf)