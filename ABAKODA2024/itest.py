for a in range(2):
    for b in range(2):
        for c in range(2):
            for d in range(2):
                print(f"{a}{b}{c}{d} : {(a^b^c) & (a^b^d)}")