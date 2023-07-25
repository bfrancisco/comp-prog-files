import random, subprocess

def generate():
    s = "4 50\n"
    for i in range(4):
        s += str(random.randint(1, 50)) + "\n"
    return s

passed = 0
while True:
    test_case = generate()
    with open('input.txt', mode='w') as f:
        print(test_case, file=f)
    p1 = subprocess.run(
        'DynamicProgramming/a.exe < input.txt',
        check=True, shell=True, capture_output=True, text=True
    )
    p2 = subprocess.run(
        'python3 DynamicProgramming/Darts.py < input.txt',
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