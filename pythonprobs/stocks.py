# needs concrete observations to understand!

D = int(input())
M = int(input())
N = int(input())
K = int(input())
x = abs(M - N) # absolute difference

if x % K == 0: # if x is divisible by k
    count = x / K
    
    if (count % 2 == 0 and D % 2 == 0) or (count % 2 != 0 and D % 2 != 0):
        if D >= count:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
else:
    print("NO")