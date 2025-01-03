words = ["squawk", "chirp", "quack"]
freq = {ch:0 for ch in "squawkchirp"}

A,B,C = map(int, input().split())
s = input()

for ch in s:
    if ch in freq: freq[ch] += 1

sw = min(freq['s'], freq['w'])
hirp = min([freq['h'], freq['i'], freq['r'], freq['p']])
quak = min([freq['q'], freq['u'], freq['a'], freq['k']])
c = freq['c']

# abc, acb, bac, bca, cab, cba
all_pos = [
    abc(sw, hirp, quak, c), acb(sw, hirp, quak, c), 
    bac(sw, hirp, quak, c), bca(sw, hirp, quak, c), 
    cab(sw, hirp, quak, c), cba(sw, hirp, quak, c)
]