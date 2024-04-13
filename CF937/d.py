divs = []
for bit in range(2, 33):
    ds = str(bin(bit))[2:]
    d = int(ds)
    divs.append(d)
# print(divs)

def rec(x):
    if x == 1:
        return 1
    good = 0
    for d in divs:
        if x % d == 0:
            good |= rec(x//d)
    
    return good
    

for _ in range(int(input())):
    n = int(input())

    print("YES" if rec(n) else "NO")