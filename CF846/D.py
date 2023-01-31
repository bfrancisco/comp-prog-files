import sys
for _ in range(int(input())):
    input()

    n = int(input())
    ans = 0
    bit = 0
    while (n != 0):
        print("- " + str(pow(2, bit)), flush=True)
        sys.stdout.flush()
        input()
        temp = int(input())
        if temp != n:
            ans += pow(2,bit)
            n = temp
        bit += 1

    print("! " + str(ans), flush=True)
    sys.stdout.flush()

