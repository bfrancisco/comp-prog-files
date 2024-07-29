MX = 10000
for a in range(1000, MX+1):
    for b in range(1000, MX+1):
        if (a*a+b*b) == 4072324:
            print(a, b)
        
print("done")