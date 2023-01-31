for a in range(1, 50):
    for b in range(a+1, 50):
        # print("a:", a)
        # print("b:", b)
        if (a ^ b == (a+b)//2):
            print(a, b, a^b)
            print(bin(a^b)[2:])
            print(bin(a)[2:])
            print(bin(b)[2:])
