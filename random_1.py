def physicalCash(x):
    x = int(x)
    if x < 0:
        return
    elif x > 0:
        onek = int(x//1000)
        if x >= 1000:
            x -= 1000*onek
        fiveh = int(x//500)
        if x >= 500:
            x -= 500*fiveh
        twoh = int(x//200)
        if x >= 200:
            x -= 200*twoh
        oneh = int(x//100)
        if x >= 100:
            x -= 100*oneh
        fiftyp = int(x//50)
        if x >= 50:
            x -= 50*fiftyp
        twentyp = int(x//20)
        if x >= 20:
            x -= 20*twentyp
        coins = x
    
        print("1000-peso bills: {}".format(onek))
        print("500-peso bills: {}".format(fiveh))
        print("200-peso bills: {}".format(twoh))
        print("100-peso bills: {}".format(oneh))
        print("50-peso bills: {}".format(fiftyp))
        print("20-peso bills: {}".format(twentyp))
        print("Coins: {}".format(coins))

print(physicalCash(int(input())))