out = []
for i in range(int(input())):
    name, score = map(str, input().split())
    out.append((-int(score), name))

out.sort()
for score, name in out:
    print(name, -score)