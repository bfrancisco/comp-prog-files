def fnum(x):
    if x > 10 and str(x)[-2:] in ["11", "12", "13"]:
        return str(x) + 'th'
    elif x%10 == 1:
        return str(x) + "st"
    elif x%10 == 2:
        return str(x) + "nd"
    elif x%10 == 3:
        return str(x) + "rd"
    else:
        return str(x) + "th"

def codemas(x):
    print(f"On the {fnum(x)} day of Codemas, my computer gave to me,")

def syntax(x):
    if x == 2:
        print("A syntax error on line three!")
    else:
        print("And a syntax error on line three!")

def warning(x):
    if x == 5:
        print("FIVE! COMPILER! WARNINGS!!!")
    else:
        print(f"{x} compiler warnings,")

def f(x):
    return x*(x+1) // 2

def bisearch(i):
    l = 1
    r = 1000000001
    while r-l > 1:
        mid = (r+l)//2
        val = f(mid)
        if val < i:
            l = mid
        elif val > i:
            r = mid
        else:
            l = mid
            r = mid+1
    #print(l, r)
    if f(l) == i:
        return 1, l
    elif f(r)-1 == i:
        return 2, -1
    else:
        return 3, f(r) - i

n, q = [int(i) for i in input().split()]
limit = n + f(n)
for _ in range(q):
    i = int(input())
    if i > limit:
        print("Codemas is already over!")
        continue
    
    mode, x = bisearch(i)
    if mode == 1:
        codemas(x)
    elif mode == 2:
        syntax(i)
    else:
        warning(x)