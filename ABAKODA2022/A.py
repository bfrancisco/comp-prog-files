def solve(outcome):
    if n == 3:
        bob = True
        for i in range(3):
            if s[i] != names[1][i] and s[i] != '.':
                bob = False
        if bob:
            outcome.append(2)
    if n == 5:
        alice = True
        cindy = True
        for i in range(5):
            if s[i] != names[0][i] and s[i] != '.':
                alice = False
            if s[i] != names[2][i] and s[i] != '.':
                cindy = False
        if alice:
            outcome.append(1)
        if cindy:
            outcome.append(3)

s = input()
n = len(s)
names = ["Alice", "Bob", "Cindy"]
outcome = []
db = {1:"Alice", 2:"Bob", 3:"Cindy"}
solve(outcome)

if len(outcome) > 1:
    print("CAN'T TELL")
elif not outcome:
    print("SOMETHING'S WRONG")
else:
    print(db[outcome[0]])

