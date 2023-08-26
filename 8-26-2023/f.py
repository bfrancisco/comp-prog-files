from math import pi
r,s,h = map(int, input().split())
d = 2*pi*(r/s) / h
rd = round(d)
print(rd, d)
if (d < rd):
    

