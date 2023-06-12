count = 0
denom = 0
suits = "HSCD"
# S H H
# 1H13H2H
def rb(s):
  global count
  global denom
  if len(s) == 3:
    db = {'H':0, 'S':0, 'C':0, 'D':0}
    for card in s:
      db[card[-1]] += 1

    if db['H'] == 1:
      count += 1
      # print(s)
    denom += 1
    
    return

  for i in range(1, 13+1):
    for c in suits:
      s.append(str(i) + c)
      rb(s)
      s.pop()

rb([])
print(count)
print(denom)
print(count/denom)


  