for _ in range(int(input())):
    r,s,x,y,w = map(int, input().split())

    er = w*(s-r+1) - r + 1
    print(er)