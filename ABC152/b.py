a, b = map(int, input().split())
z = [str(a)*b, str(b)*a]
z.sort()
print(z[0])