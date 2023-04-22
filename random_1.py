# Format: Finished 'verify_fb_token' in 0.0000 secs

db = {}
inp = input().split()
while inp[0] != 'e':
    func_name = inp[1][1:-1]
    time = float(inp[3])

    if func_name not in db:
        db[func_name] = [1, time]
    else:
        db[func_name][0] += 1
        db[func_name][1] += time
    
    inp = input().split()

print()

for k, v in db.items():
    print(k, " : ", db[k][1] / db[k][0], "seconds in", db[k][0], "runs")