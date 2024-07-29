MXN = 1000
prime = [True for i in range(MXN+1)]

def sieve():
    p = 2
    while p*p <= MXN:
        if prime[p]:
            i = p*p
            while i <= MXN:
                prime[i] = False
                i += p
        p += 1

sieve()

# c = 20
# for i in range(1, MXN+1):
#     if prime[i]:
#         c -= 1
#         print(i, end=', ')
#     if c == 0:
#         break

# first 20 primes
# p20 = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67]
# # denoms = [1]

# # for e in p20[1:]:
# #     denoms.append(denoms[-1]*e)

# # print(denoms)

primes = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 
          29, 31, 37, 41, 43, 47, 11111
        ]
denoms = [1, 2, 6, 30, 210, 
          2310, 30030, 510510, 
          9699690, 223092870, 6469693230, 
          200560490130, 7420738134810, 
          304250263527210, 13082761331670030, 
          614889782588491410, 10**18+1
        ]

difs = [0, 1, 2]
mul = 2
for i in range(2, 16):
    mul += (primes[i+1] - primes[i])
    difs.append(difs[-1]*mul)

print(difs)
print(len(difs))

nums = []
for i in range(16):
    nums.append(denoms[i] - difs[i])

print(nums)
print(len(nums))
