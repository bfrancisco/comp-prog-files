n = int(input())
s = list(input())
m = int(input())
t = []
for i in range(m):
    if i%2==0:
        t.append('a')
    else:
        t.append('b')

qsi = []
for i in range(n):
    if s[i] == '?':
        qsi.append(i)
sq = set(qsi)

db = {}
for bit in range(1 << len(qsi)):
    a = s[::]
    for i in range(len(qsi)):
        if (bit & (1 << i)):
            a[qsi[i]] = 'a'
        else:
            a[qsi[i]] = 'b'
    
    i = 0
    beauty = 0
    r = 0
    while i < n-m+1:
        if a[i:i+m] == t:
            beauty += 1
            i += m
            for j in range(i, i+m):
                if j in sq:
                    r += 1
        else:
            i += 1

        db = 

