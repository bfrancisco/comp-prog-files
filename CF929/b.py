for _ in range(int(input())):
    n = int(input())
    a = [int(i)%3 for i in input().split()]
    r = sum(a)%3
    one = len([i for i in a if i==1])
    two = len([i for i in a if i==2])
    # print(r)
    if r == 2:
        print(1)
    elif (r==1):
        if (one):
            print(1)
        else:
            print(2)
    else:
        print(0)