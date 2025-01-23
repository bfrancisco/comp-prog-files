# bruteforce

def is_based(x):
    leading_zero = False
    for i in range(0, 60, 4):
        
        val = sum([2**j for j in range(4) if x & (1 << (i+j))])
        if 0 < val and val < 10:
            return False
        elif val == 0:
            leading_zero = True

        if val > 0 and leading_zero:
            return False

    return True


for _ in range(int(input())):
    n = int(input())

    x1 = n-1
    while not is_based(x1):
        x1 -= 1
        if x1 < 0:
            x1 = -1
            break
    
    x2 = n+1
    while not is_based(x2):
        x2 += 1
    
    print(x1, hex(x1))
    print(x2, hex(x2))
    
