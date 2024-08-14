abc = "abcdefghijklmnopqrstuvwxyz"
for _ in range(int(input())):
    s = input()
    done = False
    for i in range(len(s) - 1):
        if s[i] == s[i+1]:
            done = True
            if (s[i] != 'a'):
                print(s[:i+1] + 'a' + s[i+1:])
            else:
                print(s[:i+1] + 'b' + s[i+1:])
            break

    if not done:
        if (s[-1] != 'a'):
            print(s + 'a')
        else:
            print(s + 'b')

                
    
