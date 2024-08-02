from itertools import combinations

N = int(input())
first_word = input()
words = [input() for i in range(N-1)]
alpha = "qwertyuiopasdfghjklzxcvbnm"

disti = set()
wordset = [set(word) for word in words + [first_word]]
for ws in wordset:
    if len(ws) != 3:
        print(0)
        exit()

for w in words:
    for c in w:
        if c not in first_word:
            disti.add(c)

if len(disti) > 15:
    print(0)
    exit()

print(disti, len(disti))


for c in alpha:
    if len(disti) == 15:
        break
    if c not in first_word and c not in disti:
        disti.add(c)
    
letters = list(disti)

impossible_map = {c : set() for c in alpha}
for l1 in first_word:
    for l2 in first_word:
        if l1==l2: continue
        impossible_map[l1].add(l2)
for word in words:
    for l1 in word:
        for l2 in word:
            if l1==l2: continue
            impossible_map[l1].add(l2)

print(disti, len(disti))
for co in combinations(letters, 10):
    combi = list(co)
    dices = [set(combi[:5]), set(combi[5:]), set()]
    
    dices[0].add(first_word[0])
    dices[1].add(first_word[1])
    dices[2].add(first_word[2])
    
    for c in letters:
        if c not in dices[0] and c not in dices[1]:
            dices[2].add(c)

    good = True    
    for dice in dices:
        for l1 in dice:
            for l2 in dice:
                if l1==l2: continue
                if l2 in impossible_map[l1]:
                    good = False
                    break
            if not good:
                break
    
    if good:
        print('asd')
        for diceset in dices:
            dice = list(diceset)
            print(*dice, sep='', end=' ')
        print()
        # cnt += 1
        # print(letters)

        break
# print(cnt)


