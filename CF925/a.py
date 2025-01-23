alp = "abcdefghijklmnopqrstuvwxyz"
for _ in range(int(input())):
    n = int(input())

    done = False
    for i in alp:
        for j in alp:
            for k in alp:
                if alp.index(i) + alp.index(j) + alp.index(k) + 3 == n:
                    print(i,j,k, sep='')
                    done = True
                    break 
            if done: break
        if done: break
    
