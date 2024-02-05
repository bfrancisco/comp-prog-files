for bit in range(1 << 3):
    A = (bit & (1 << 2)) >> 2
    B = (bit & (1 << 1)) >> 1
    C = bit & 1

    X = 1 - ( ((1-A) & B) | ((1-B) & (1-A) & C) )
    Y = ( (1-B) & (1-C) ) | A

    print(X, Y)