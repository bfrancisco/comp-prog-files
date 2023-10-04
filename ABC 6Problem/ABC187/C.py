n = int(input())
bank = set()
a = []
pas = "satisfiable"
for i in range(n):
    s = input()
    if s[0] == '!':
        bank.add(s)
    else:
        a.append(s)
for s in a:
    if '!'+s in bank:
        pas = s
        break

print(pas)

