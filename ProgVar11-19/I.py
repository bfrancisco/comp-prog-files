t, d = [x for x in input().split()]
arr = [int(x) for x in input().split()]
days = ['Sat', 'Sun', 'Mon', "Tue", "Wed", "Thu", "Fri"]
ans = []
for x in range(int(d)):
    if arr[x] > 90:
        s = days.index(t)
        count = 0
        while (days[s] != "Sat" or days[s] != "Sun"):
            count += 1
            s = (s+2)%7
        arr[x] -= count*30
        s = 0
        if arr[x] > 90:
            p = 0
            while x > 30:
                p = x//90
                x //= 90
                x += p
            x += p
        k = (30-arr[x])%30  
    
    elif arr[x] == 0:
        k = 30
    else:
        k = (30-arr[x])%30      
    s = days.index(t)
    s += k%7
    s %= 7
    if days[s] == 'Sat':
        k += 2
    elif days[s] == 'Sun':
        k += 1
    ans.append(k)
print(min(ans))
    