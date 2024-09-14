n = int(input())
a = [input() for i in range(n)] + ["!!"]

b = []
for i in range(n):
    if a[i] == "Present!" or a[i+1] == "Present!":
        continue
    b.append(a[i])

if b:
    print(*b, sep='\n')
else:
    print("No Absences")