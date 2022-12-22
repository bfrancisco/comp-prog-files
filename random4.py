ranking = {}
for i in range(int(input())):
    name, score = map(str, input().split())
    ranking[name] = i+1

for i in range(int(input())):
    print(ranking[input()])