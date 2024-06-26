import random, subprocess

def generate():
    '''Insert generator here'''
    n = random.randint(3, 7)
    a = random.randint(1, n)
    b = random.randint(1, n)
    while (a==1 and b==n) or (b==1 and a==n):
        n = random.randint(3, 7)
        a = random.randint(1, n)
        b = random.randint(1, n)

    return f"{n} {a} {b}"

solution = input("Solution file: ")
brutef = input("Bruteforce file: ")

passed = 0
while passed <= 1000:
    test_case = generate()
    with open('input.txt', mode='w') as f:
        print(test_case, file=f)
    p1 = subprocess.run(
        f'python3 {brutef} < input.txt',
        check=True, shell=True, capture_output=True, text=True
    )
    p2 = subprocess.run(
        f'./{solution} < input.txt',
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