import heapq

N = 200001
n, q = map(int, input().split())
hps = [[] for i in range(N)]
infantval = {} # id : value
db = {} # id : kindergarten
for i in range(1,n+1):
    a, b = map(int, input().split())
    heapq.heappush(hps[b], -a)
    infantval[i] = -a
    db[i] = b

# initial min kindergarten
kinder = 1000000
out = -1000000000
for i in range(1, N):
    if hps[i] and hps[i][0] > out:
        kinder = i
        out = hps[i][0]
print(out)
for i in range(1,4):
    print(hps[i])

for i in range(q):
    c, d = map(int, input().split())
    val = infantval[c]
    kinderg = db[c]
    place = 0
    
    while hps[kinderg][place] != val:
        place += 1
    #print(place, hps[kinderg])
    print(val, place)
    hps[kinderg][place] = hps[kinderg][0]
    heapq.heapify(hps[kinderg])
    print(hps[kinderg].pop())

    heapq.heappush(hps[d], val)
    db[c] = d

    for i in range(1,4):
        print(hps[i])
    out = max([hps[kinderg][0], hps[d][0], out])

    print(-out)