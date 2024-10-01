s, n = map(int, input().split())
 
yt = []
nt = []
 
for _ in range(n):
    d, t = input().split()
    d = int(d)
 
    if t == 'y': yt.append(d)
    else: nt.append(d)
 
yt.sort()
nt.sort()
 
y_vis = [False for _ in range(len(yt))]
n_vis = [False for _ in range(len(nt))]
curr_time = 1
ptr = 0
for i in range(len(yt)):
    if curr_time > yt[i]:
        # print(1, curr_time, nt[j])
        print("no")
        exit()
    
    y_vis[i] = True
    for j in range(ptr, min(ptr+(s-1), len(nt))):
        if curr_time > nt[j]:
            # print(2, curr_time, nt[j])
            print("no")
            exit()
        
        n_vis[j] = True
        ptr += 1
    curr_time += 1
 
 
for i in range(len(nt)):
    if not n_vis[i]:
        for j in range(ptr, min(ptr+s, len(nt))):
            if curr_time > nt[j]:
                # print(2, curr_time, nt[j])
                print("no")
                exit()
            
            n_vis[j] = True
            ptr += 1
        curr_time += 1
 
print("yes")