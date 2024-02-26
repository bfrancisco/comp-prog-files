def rev(n):
    ns = int(str(n)[::-1])
    return ns
MX = 1000000
db = {}
for d in range(9, MX, 9):
    for n in range(1, MX):
        if (rev(n) == n + d):

            print(n, rev(n), d)
    print()

# print(len(s))
# for e in s:
#     print(e)
