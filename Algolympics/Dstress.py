import subprocess

passed = 0
a = ["1\n3\nA*B=C",
    "1\n3\nA*C=B",
    "1\n3\nB*A=C",
    "1\n3\nB*C=A",
    "1\n3\nC*A=B",
    "1\n3\nC*B=A",
    "1\n3\nA/B=C",
    "1\n3\nA/C=B",
    "1\n3\nB/A=C",
    "1\n3\nB/C=A",
    "1\n3\nC/A=B",
    "1\n3\nC/B=A"]

while True:
    test_case = a[passed]
    # print(test_case)
    with open('Algolympics\input.txt', mode='w') as f:
        print(test_case, file=f)
    p1 = subprocess.run(
        'Algolympics\output\D21.exe < Algolympics\input.txt',
        check=True, shell=True, capture_output=True, text=True
    )
    p2 = subprocess.run(
        'Algolympics\output\D6.exe < Algolympics\input.txt',
        check=True, shell=True, capture_output=True, text=True
    )
    if p1.stdout != p2.stdout:
        print('Failed!')
        print(test_case)
        print()
        print('Expected:\n', p1.stdout, sep='')
        print('Output:\n', p2.stdout, sep='')
        break
    else:
        print(f'{passed + 1} cases passed')
    passed += 1
    