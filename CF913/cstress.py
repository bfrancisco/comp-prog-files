import random, subprocess

def generate():
    tst = "1\n"
    n = random.randint(1, 8)
    s = ""
    for i in range(n):
        x = random.randint(97, 97+25)
        r = random.randint(1, 3)
        if r==1:
            s += chr(x)
        s += chr(x)
        n+=1
    tst += str(n) + '\n'
    tst += s + '\n'
    return tst

passed = 0
while passed <= 10000:
    test_case = generate()
    with open('input.txt', mode='w') as f:
        print(test_case, file=f)
    p1 = subprocess.run(
        'python3 c.py < input.txt',
        check=True, shell=True, capture_output=True, text=True
    )
    p2 = subprocess.run(
        './c.exe < input.txt',
        check=True, shell=True, capture_output=True, text=True
    )
    if p1.stdout != p2.stdout:
        print('Failed!')
        print('Expected:', p1.stdout)
        print('Output:', p2.stdout)  
        print("Test Case:\n" + test_case)
        break

    passed += 1
    print(f'{passed} cases passed')