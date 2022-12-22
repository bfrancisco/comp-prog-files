# main idea is the list would be "randomized" if an element is k places away from its original position.

from collections import deque
 
n, k = map(int, input().split())
s = deque([i for i in input().split()])
if k > n//2:
    print('NO')
    exit()
print('YES')
s.rotate(k) # rotate the list. example: [1,2,3] --> [3,1,2] --> [2,3,1]
print(*s)