#import io,os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n = int(input())
N = 2**n
a = list(map(int, input().split()))

# list of pairs, where sum of pairs is the highest given (firstval | secondval <= index)
high2 = [] 

for i in range(N):
    high2.append([a[i], 0]) # zero is a placeholder

for i in range(n):
    #print(i)
    for j in range(N):        
        power = 1 << i # or 2**i
        # if no intersection
        if j&(power) == 0:
            # combine
            comb = j | power
            # dp: collect high2 of lower number and current number. get 2 highest values and update high2[comb]
            lst = [high2[j][0], high2[j][1], high2[comb][0], high2[comb][1]]
            lst.sort(reverse=True)  
            high2[comb][0] = lst[0]
            high2[comb][1] = lst[1]
            
#print(*high2, sep='\n')
#print()
mx = -1
for k in range(1, N):
    val = sum(high2[k])
    if val > mx:
        mx = val
    print(mx)