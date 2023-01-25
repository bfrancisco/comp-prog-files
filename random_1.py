for _ in range(int(input())):
    n = int(input())
    a = input()
    out = []
    val = int(a[0])
    for i in range(1, n):
        if val == 1:
            out.append('-')
        else:
            out.append('+')

        if a[i] == '1':
            val = 1 - val
            
    print(''.join(out))