pattern = [
    [
        '0111',
        '1100',
        '1111',
        '0101',
    ],
    [
        '1000',
        '0011',
        '0000',
        '1010', 
    ]
]

def scanAmogus(n, jump, p):
    amoguses = 0
    for section in range(0, n, (16+jump*4)):
        Amogood = True
        for i in range(4):
            for j in range(4):
                index = section + i*(4+jump) + j
                if index >= n or pattern[p][i][j] != s[index]:
                    Amogood = False
                    break
        if Amogood:
            amoguses += 1
        
    return amoguses


n = int(input())
s = input()


jump = 0
max_amoguses = 0 
while (4+jump)*4 - jump <= n:
    max_amoguses = max(max_amoguses, scanAmogus(n, jump, 0))
    max_amoguses = max(max_amoguses, scanAmogus(n, jump, 1))
    jump += 1

print(max_amoguses)
