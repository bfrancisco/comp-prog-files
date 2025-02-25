import random, subprocess
from itertools import permutations
def generate():
    n = random.randint(5, 7)
    perm = list(permutations([i+1 for i in range(n)]))
    x = random.randint(0, len(perm))
    p = []
    for i in perm[x]:
        p.append(i)
    ret = f'{n}\n'
    for i in p:
        ret += f'{i} '
    ret += "\n"
    # print(n)
    print("ret: ", ret)
    return ret



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
        f'python3 {solution} < input.txt',
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