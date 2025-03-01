ahm, bhm = input().split(':'), input().split(':')

a = int(ahm[0])*60 + int(ahm[1])
b = int(bhm[0])*60 + int(bhm[1])
x = (a+b)//2
print(f'{"0" if x//60 < 10 else ""}{x//60}:{"0" if x%60 < 10 else ""}{x%60}')
