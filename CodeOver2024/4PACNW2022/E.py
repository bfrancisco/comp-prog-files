N = int(input())
tubes = [[int(i) for i in input().split() if i != '0'] for j in range(N+1)]
ans = []

def print_tubes():
    print()
    print("+"*20)
    for tube in tubes:
        print(*tube)
    print("+"*20)
    print()

def transfer(source, target):
    ball = tubes[source].pop()
    tubes[target].append(ball)
    ans.append((source+1, target+1))
    # print(source+1, target+1)
    assert(len(tubes[target]) <= 3)

def freeup_last():
    while tubes[-1]:
        for i in range(N):
            if len(tubes[i]) < 3:
                transfer(N, i)
                break

def unfill_to_last(source):
    while True:
        if len(tubes[source]) == 1 or tubes[source].count(tubes[source][0]) == len(tubes[source]):
            break
        transfer(source, N)

def fill_util(target, source, depth):
    free = N
    if source == N:
        for i in range(source + 1, N):
            if i == target or i == source: continue
            if len(tubes[i]) < 3:
                free = i
                break
    if depth == 0:
        transfer(source, target)
    elif depth == 1:
        transfer(source, free)
        transfer(source, target)
    elif depth == 2:
        if len(tubes[target]) == 1:
            transfer(source, target)
            transfer(source, free)
            transfer(source, target)
            transfer(free, source)
            transfer(target, source)
            transfer(target, free)
            transfer(source, target)
        else:
            transfer(source, free)
            transfer(source, target)
            transfer(source, free)
            transfer(target, source)
            transfer(free, target)

def fill(source):
    ball = tubes[source][0]
    for i in range(source+1, N+1):
        if ball in tubes[i]:
            # print_tubes()
            unfill_to_last(source)
            # print_tubes()
            # print("TOFILL:", source+1, i+1, ball)
            fill_util(source, i, tubes[i][::-1].index(ball))
            # print_tubes()
            freeup_last()
            return fill(source)

# print_tubes()   
freeup_last()
for i in range(N):
    fill(i)
    

# print_tubes()
for tube in tubes:
    assert(len(set(tube)) <= 1)
assert(len(ans) <= 20*N)

print(len(ans))
for a, b in ans:
    print(a, b)