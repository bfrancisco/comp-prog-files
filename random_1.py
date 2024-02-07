n = 3
for bit in range(1 << n):
    A = (True if bit & 1 else False)
    B = (True if bit & (1 << 1) else False)
    C = (True if bit & (1 << 2) else False)
    inv = (not A)
    or1 = inv or B
    or2 = A or C
    or3 = inv or C
    and1 = or3 and or2

    print(bin(bit)[2:], and1)