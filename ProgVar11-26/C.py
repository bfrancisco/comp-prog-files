b,l = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]
m_arr = []
total = 0
for x in range(l):
    if (l-x-1) %2 == 0:
        m_arr.append(arr[x])
    else:
        m_arr.append(-arr[x])
total = 0
for x in range(l):
    total += m_arr[x]
    total %= b+1
if total == 0:
    print("0 0")
    exit()
for x in range(l):
    if m_arr[x] > 0:
        if arr[x] - total >= 0:
            print(x+1, arr[x]-total)
            exit()
    else:
        if total - m_arr[x] >= b+1:
            print(x+1, arr[x] - (b+1) + total)
            exit()
print("-1 -1")