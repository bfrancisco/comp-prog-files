n = int(input())
x = int(n**(1/2))
a, b = sum([r*(r+n//r)*(n//r+1-r)//2 for r in range(1, x+1)]), x*(x+1)*(2*x+1)//6
print(2*a-b)