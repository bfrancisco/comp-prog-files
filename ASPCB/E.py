vowels = "aeiouAEIOU"
translate = {
    "I" : "ko",
    "You" : "mo",
    "He" : "niya",
    "She" : "niya",
    "We" : "natin",
    "They" : "nila",
}

def simuno(noun):
    return translate[noun]

def kuhainunangsilabol(verb):
    unangsilabol = ""
    for letra in verb:
        unangsilabol += letra
        if letra in vowels:
            break
    return unangsilabol

def pandiwa(verb, make):
    bago = ""

    if make == "will make":
        bago = kuhainunangsilabol(verb)
        hulapi = "in"
        for i in range(len(verb)-1, -1, -1):
            if verb[i] == 'O':
                verb = verb[:i] + "U" + verb[i+1:]
                break
            elif verb[i] == "o":
                verb = verb[:i] + "u" + verb[i+1:]
                break
            elif verb[i] in vowels:
                break

        if verb[-1] in vowels:
            hulapi = "hin"

        bago += verb + hulapi
    
    elif make == "made":
        for i in range(len(verb)):
            if verb[i] in vowels:
                bago = verb[:i] + "in" + verb[i:]
                break
            
    elif make in ["make", "makes"]:
        unangsilabol = kuhainunangsilabol(verb)
        bago = unangsilabol[:-1] + "in" + unangsilabol[-1] + verb
            
    if bago[0].islower():
        bago = bago[0].upper() + bago[1:]
    return bago

def solve():
    a = input().split()
    subj = a[0]
    make = a[1]
    verb = a[2]
    nounpunc = a[4]
    if (make == "will"):
        make = "will make"
        verb = a[3]
        nounpunc = a[5]
    # print(subj, make, verb, nounpunc)
    print(pandiwa(verb, make), simuno(subj), "ang", nounpunc)

for i in range(int(input())):
    solve()