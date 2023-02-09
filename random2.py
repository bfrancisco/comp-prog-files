## faster AC, uses string

amogus0 = "0111110011110101"
amogus1 = "1000001100001010"

def make_table(n, c, s):
    # print(c)
    table = []
    for i in range(0, n, c):
        table.append(s[i:i+c])
    
    rem = c - (n%c)
    if rem != c:
        table[-1] += ('2' * rem)

    # for r in table:
    #     print(r)

    return table

def find_pattern(r, c, table):
    amoguses = 0
    # print(r-3, c-3)
    for i in range(r-3):
        for j in range(c-3):
            pattern = ""
            for k in range(4):
                for l in range(4):
                    pattern += table[i+k][j+l]
            
            if pattern == amogus0 or pattern == amogus1:
                amoguses += 1

    return amoguses
                
                    
def main():
    n = int(input())
    s = input()
    max_amoguses = 0
    c = 4
    while c <= n:
        table = make_table(n, c, s)
        max_amoguses = max(max_amoguses, find_pattern(len(table), c, table))
        c += 1
        # print(max_amoguses)
        # print()

    print(max_amoguses)

main()