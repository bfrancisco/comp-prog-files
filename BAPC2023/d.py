n, m = map(int, input().split())
db = [[0 for i in range(26)] for i in range(m)]
# print(*db, sep='\n')
# print(ord('a') - ord('a'))
for i in range(n):
    s = input()
    for j in range(m):
        db[j][ord(s[j]) - ord('a')] += 1
    
# print(*db, sep='\n')
for j in range(m):
    mx = 0
    out = 'a'
    for i in range(26):
        if db[j][i] > mx:
            mx = db[j][i]
            out = chr(i + 97)
    print(out, end='')
    