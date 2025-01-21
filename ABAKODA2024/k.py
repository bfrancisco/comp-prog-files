r45 = {
    "#.#.#x#...#x" : '0',
    "..#..x..#..x" : '1',
    "...#.x.#...x" : '2',
    "..##.x....#x" : '3',
    "#..#.x...#.x" : '4',
    "####.x....#x" : '5',
    "####.x#...#x" : '6',
    "...#.x..#..x" : '7',
    ".###.x#...#x" : '8',
    "#...#x....#x" : '9',
}

for _ in range(int(input())):
    n = int(input())
    db = ['' for i in range(n)]
    for r in [4,6]:
        print(f"ASK ROW {r}", flush=True)
        x = input()
        for i in range(0, n*6, 6):
            db[i//6] += x[i:i+5] + 'x'

    print(f"ANSWER {''.join([r45[p] for p in db])}", flush=True)
