import sys

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
    sys.stdout.write(f"On the {fnum(x)} day of Codemas, my computer gave to me,\n")

def syntax(x):
    if x == 2:
        sys.stdout.write("A syntax error on line three!\n")
    else:
        sys.stdout.write("And a syntax error on line three!\n")

def warning(x):
    if x == 5:
        sys.stdout.write("FIVE! COMPILER! WARNINGS!!!\n")
    else:
        sys.stdout.write(f"{x} compiler warnings,\n")

def f(x):
    # inverse x = n*(n+1)/2
    r = (2*x + (1/4))**(1/2) - (1/2)
    return r

def f2(x):
    return x*(x+1) // 2

n, q = [int(i) for i in sys.stdin.readline().split()]
limit = n + f2(n)
print(limit)
for _ in range(q):
    i = int(sys.stdin.readline())
    if i > limit:
        sys.stdout.write("Codemas is already over!\n")
        continue
    
    r = f(i)
    print(r)
    if (r == r//1):
        codemas(int(r))
    elif (int(r)+1 == f(i+1)):
        syntax(i)
    else:
        warning(f2(int(r)+1) - i)