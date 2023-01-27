import heapq as hq

for _ in range(int(input())):
    n, m = map(int, input().split())

    a = [int(i) for i in input().split()]
    c = [int(i) for i in input().split()]

    q = []
    c.sort(reverse=True)

    db = {}
    for i in range(n):
        if a[i] not in db:
            db[a[i]] = 1
        else:
            db[a[i]] += 1

    for k, v in db.items():
        hq.heappush(q, -v)

    ans = 0
    for seats in c:
        if not q:
            break
        guests = -hq.heappop(q)
        # print(guests, seats)
        if guests >= seats:
            ans += seats
            hq.heappush(q, -(guests - seats))
        else:
            ans += guests
    print(ans)