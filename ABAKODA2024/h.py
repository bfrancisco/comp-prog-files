from math import ceil
for _ in range(int(input())):
    a,b,c = map(int, input().split())
    
    db = [[a, 1], [b, 2], [c, 3]]
    r = 1
    st = []
    while r <= 100:
        # print(db[0][0], db[1][0], db[2][0])
        if db[0][0] == db[1][0] and db[1][0] == db[2][0]:
            print(len(st)//2)
            for v in st:
                if type(v) == int: print(v)
                else: print(*v)
            st.clear()
            break
        db.sort()
        dif = db[2][0] - db[0][0]
        k = ceil(dif/3)

        st.append(k)
        out = [0 for i in range(4)]
        out[db[0][1]] = 3
        out[db[1][1]] = 2
        out[db[2][1]] = 1
        st.append((out[1], out[2], out[3]))
            
        db[0][0] += 3*k
        db[1][0] += 2*k
        db[2][0] += k

        r += 1
    
    if r > 100:
        print(-1)

    