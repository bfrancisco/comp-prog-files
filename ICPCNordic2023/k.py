
p2 = 1
while True:
    print(f'buf[{p2}]', flush=True)
    x = int(input())
    if x == 0:
        break
    p2 *= 2
l, r = p2//2+1, p2-1

if p2==1:
    print("strlen(buf) = 1", flush=True)
    exit()
if p2==2:
    print("strlen(buf) = 2", flush=True)
    exit()

ans = -1
while l <= r:
    m = (l+r)//2
    print(f'buf[{m}]', flush=True)
    x = int(input())
    if x == 0:
        r = m-1
        ans = m-1
    else:
        l = m+1
        ans = m

print(f'strlen(buf) = {ans+1}', flush=True)
    
