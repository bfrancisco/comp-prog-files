"""
from math import ceil

a1, a2, a3 = map(int, input().split())
b1, b2, b3 = map(int, input().split())

h2, h1 = a1//b2 * b3, b1//a2 * a3
# t2, t1 = (ceil(a1/b2) * (b3+0.5)), (ceil(b1/a2) * (a3+0.5)) 
# t2, t1 = ((a1/b2) * b3), ((b1/a2) * a3) 
# print(t1, t2)
print(h1-b3, h2+b3)
if h1-b3 == h2+b3:
    print("draw")
if h2+b3 < h1-b3:
    print("player two")
elif h2+b3 > h1:
    print("player one")
"""
from math import ceil
health1, damage1, reload1 = map(int, input().split())
health2, damage2, reload2 = map(int, input().split())

TTK1 = ceil((health2-damage1)/damage1)*reload1
TTK2 = ceil((health1-damage2)/damage2)*reload2

if TTK1 == TTK2+reload2 or TTK1+reload1 == TTK2 or TTK1 == TTK2:
    print("draw")
elif TTK1 > TTK2:
    print("player two")
elif TTK2 > TTK1:
    print("player one")

print(TTK1, TTK2)


