def predict(inp):
    db = {
        "2" : "abc",
        "3" : "def",
        "4" : "ghi",
        "5" : "jkl",
        "6" : "mno",
        "7" : "pqrs",
        "8" : "tuv",
        "9" : "wxyz",
    }
    f = open("input.txt", 'r')
    wordbank = set()
    for x in f.readlines():
        wordbank.add(x.strip())
    f.close()
    print(wordbank)
    bank = set()
    def rb(s, i, inp):
        
        if (len(s) == len(inp)):
            print(s)
            bank.add(s)
            return

        for c in db[inp[i]]:
            rb(s + c, i+1, inp)

    rb("", 0, inp)
    return bank

print(predict(input()))
