dice = [[int(i) for i in input().split()] for j in range(3)]
choices = [[0, 1, 2], [1, 0, 2], [2, 0, 1]]

for pick, a, b in choices:
    win1, win2 = 0, 0
    t1, t2 = 0, 0
    for i in range(6):
        for j in range(6):
            if dice[pick][i] > dice[a][j]:
                win1 += 1
            if dice[pick][i] != dice[a][j]:
                t1 += 1

        for k in range(6):
            if dice[pick][i] > dice[b][k]:
                win2 += 1
            if dice[pick][i] != dice[b][k]:
                t2 += 1
    
    # print(win1, t1, win2, t2)
    if win1*2 >= t1 and win2*2 >= t2 and t1>0 and t2>0:
        print(pick+1)
        exit()
    
print("No dice")