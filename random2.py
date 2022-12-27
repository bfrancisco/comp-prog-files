import math

def isperf(x):
    if int(math.sqrt(x) + 0.5) ** 2 == x:
        return True
    return False

print(isperf(1))