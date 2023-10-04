import subprocess

def generate():
    return "4 5\n9 7 5 3"


bruteforcer = "Ebrute.py"
passed = 0
while True:
    test_case = generate()
    with open('input.txt', mode='w') as f:
        print(test_case, file=f)
    p1 = subprocess.run(
        'python ' + bruteforcer + ' < input.txt',
        check=True, shell=True, capture_output=True, text=True
    )
    p2 = subprocess.run(
        'solve.exe < input.txt',
        check=True, shell=True, capture_output=True, text=True
    )
    if p1.stdout != p2.stdout:
        print('Failed!')
        print('Expected:', p1.stdout)
        print('Output:', p2.stdout)
        break

    passed += 1
    print(f'{passed} cases passed')