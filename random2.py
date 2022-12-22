db = {i:0 for i in "ABKD"}
for i in range(int(input())):
    x = input()
    for c in x:
        db[c] += 1
for letter in "ABKD":
    print(db[letter], end = ' ')