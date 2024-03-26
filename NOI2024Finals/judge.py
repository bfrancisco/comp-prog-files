"""Judge program for the problem "Infinity War" for local testing.

Run one of the following commands, where the part after "--" is how you might
run your program normally in a non-interactive task:

    pypy3 interactive_runner.py  pypy3 judge.py noi.txt  --  ./sol
    pypy3 interactive_runner.py  pypy3 judge.py noi.txt  --  sol.exe
    pypy3 interactive_runner.py  pypy3 judge.py noi.txt  --  pypy3 sol.py
    python3 interactive_runner.py  python3 judge.py noi.txt  --  python3 djoke.py

Notice that in the first and second, there would usually be a compilation step
before running, which you should run in your usual way before using this tool.

The judge also accepts arguments such as -n; run

    pypy3 judge.py --help

for more information.

To use arguments with the interactive runner, simply pass the arguments to the
judge command, e.g.,

    pypy3 interactive_runner.py  pypy3 judge.py noi.txt -t 50  --  ./sol

We recommend running this in verbose mode (either -v 1 or -v 2), e.g.,

    pypy3 interactive_runner.py  pypy3 judge.py noi.txt -v 2  --  ./sol
"""

from fractions import Fraction as Frac
from pathlib import Path
from sys import stderr


T = 2500
Q = 250000
MAX_GUESS_K = 100
MAX_I = 10**9
SCORE_PREC = Frac(10**2)


def get_score(s, a):

    s = Frac(s)
    a = Frac(a)

    get_score.raw_score = raw_score = 50*s + min(50, 440*s / (a + 6))

    # round the score appropriately
    return int(raw_score * SCORE_PREC) / SCORE_PREC


def mean(seq):
    return Frac(sum(seq)) / len(seq)


def get_s(d):
    assert d >= 0
    if d == 0: return Frac(1)
    if d == 1: return Frac(1) / 10
    if d == 2: return Frac(1) / 20
    return Frac(0)


def snap(rand, seq):
    return [seq[i] for i in sorted(rand.sample(range(len(seq)), len(seq) + 1 >> 1))]


def interact_infinity_war(rand, user, names, *, t=T, q=Q, prefix='', verbose=0, wrong=Exception):

    n = len(names)

    if verbose:
        print(f"{prefix}Starting interaction with {t} test cases and up to {q} queries. There are {n} names.", file=stderr, flush=True)

    print(t, q, n, file=user, flush=True)

    # kmax = [lg(n)]
    # kmax <= lg(n)
    # 2^kmax <= n
    kmax = 0
    while 2**(kmax + 1) <= n: kmax += 1
    assert 2**kmax <= n < 2**(kmax + 1)

    if verbose:
        print(f"{prefix}Valid values of k will be between {1} and {kmax}.", file=stderr, flush=True)

    ds = []
    qc = 0
    for casec in range(1, t + 1):

        k = None
        alive = []
        
        # pick a k
        k = rand.randint(1, kmax)

        # simulate k snaps
        alive[:] = names
        for it in range(k):
            alive = snap(rand, alive)

        if not alive:
            raise RuntimeError("Somehow, everyone died. Shouldn't happen!")

        def query(i):
            i -= 1
            assert i >= 0
            return alive[i] if i < len(alive) else rand.choice(alive)

        if verbose >= 2:
            print(f"{prefix}Starting case {casec} with {k=} (so far: a total of {qc} queries performed).", file=stderr, flush=True)

        qcc = 0
        while True:
            [cmd] = user.read.token()
            if cmd == 'A':
                [guess_k] = user.read.space.int(1, MAX_GUESS_K).eoln
                d_i = abs(guess_k - k)

                casec += 1
                print('OK', file=user, flush=True)
                break
            elif cmd == 'Q':
                [i] = user.read.space.int(1, MAX_I).eoln

                qcc += 1
                qc += 1
                if qc > q:
                    raise wrong("Maximum query count exceeded")

                print(query(i), file=user, flush=True)
            else:
                raise wrong(f"Unknown command: {cmd!r}")

        ds.append(d_i)
        if verbose >= 2:
            print(f"{prefix}You made {qcc} queries in this test case, and got {d_i = }", file=stderr, flush=True)

    if verbose:
        print(f"{prefix}The solution performed {qc} queries overall.", file=stderr, flush=True)

    return mean([get_s(d) for d in ds]), Frac(qc) / t


### @@ rem {
def main():
    from collections import deque
    from random import Random, getrandbits
    from sys import stdin, stdout, exit as sysexit

    class Wrong(Exception):
        pass

    class InteractorException(Exception):
        pass

    class ChainRead:
        def __init__(self, stream):
            self._s = stream
            self._r = deque()
            super().__init__()

        def __iter__(self):
            while self._r:
                yield self._r.popleft()

        def __call__(self): return list(self)

        def int(self, *a, **kw):
            self._r.append(self._s.read_int(*a, **kw)); return self

        def token(self, *a, **kw):
            self._r.append(self._s.read_token(*a, **kw)); return self

        @property
        def space(self):
            self._s.read_space(); return self

        @property
        def eoln(self):
            self._s.read_eoln(); return self

    class Stream:
        def __init__(self, reader, writer):
            self.reader = reader
            self.writer = writer
            self.read = ChainRead(self)
            self.pieces = deque()
            super().__init__()

        def read_int(self, a, b):
            piece = self.next_piece()
            try:
                res = int(piece)
            except ValueError:
                raise Wrong(f"Expected an int in [{a}, {b}], got {piece!r}")
            if not (a <= res <= b):
                raise Wrong(f"{res} not in [{a}, {b}]")
            return res

        def read_token(self):
            return self.next_piece()

        def read_space(self):
            self.expect(' ')

        def read_eoln(self):
            self.expect('\n')

        def expect(self, expec):
            got = self.next_piece()
            if expec != got:
                raise Wrong(f"Expected {expec!r}, got {got!r}")

        def next_piece(self):
            if not self.pieces:
                line = self.reader.readline()
                endl = line.endswith('\n')
                if endl: line = line[:-1]
                for v in line.split(' '):
                    self.pieces.append(v)
                    self.pieces.append(' ')
                # discard last space
                self.pieces.pop()
                if endl: self.pieces.append('\n')

            if not self.pieces:
                raise Wrong("No more output")

            return self.pieces.popleft()

        def write(self, *args, **kwargs): self.writer.write(*args, **kwargs)
        def flush(self, *args, **kwargs): self.writer.flush(*args, **kwargs)

    from argparse import ArgumentParser

    parser = ArgumentParser(description="Local testing judge for 'Infinity War'")
    parser.add_argument('names_file', type=Path, help='file containing character names')
    parser.add_argument('-t', '--test-cases', type=int, help='number of test cases to simulate (default: %(default)s)', default=T)
    parser.add_argument('-q', '--max-queries', type=int, help="maximum number of allowed queries (default: %(default)s)", default=Q)
    parser.add_argument('-s', '--seed', type=int, help='random seed (default: random from system time or system random source)')
    parser.add_argument('-v', '--verbose', type=int, help='Verbosity level (default: %(default)s)', default=0)

    args = parser.parse_args()

    seed = args.seed
    if seed is None:
        seed = getrandbits(64)

    if args.verbose:
        print(f'Using random seed {seed}...', file=stderr)

    try:
        with args.names_file.open() as f:
            names = [line.rstrip('\n') for line in f.readlines()]
    except PermissionError:
        print(f"Failed reading the file {args.names_file}: You do not seem to have permission to read the file.", file=stderr)
        sysexit(2)
    except FileNotFoundError:
        print(f"Failed reading the file {args.names_file}: It does not seem to exist.", file=stderr)
        sysexit(2)
    except Exception as exc:
        print(f"Failed reading the file {args.names_file}:", exc, file=stderr)
        sysexit(2)

    try:

        for name in names:
            if not name:
                raise RuntimeError(f"empty name invalid")

            if any(ch.isspace() for ch in name):
                raise RuntimeError(f"no whitespace allowed in a name; got {name!r}")

        if len(set(names)) != len(names):
            raise RuntimeError("there must not be any duplicates in the list of names")

        if not names:
            raise RuntimeError("there must be at least one name")

        s, a = interact_infinity_war(
                Random(seed),
                Stream(stdin, stdout),
                names,
                t=args.test_cases,
                q=args.max_queries,
                wrong=Wrong,
                verbose=args.verbose,
            )
    except Wrong as exc:
        [message] = exc.args
        print("The answer is incorrect:", message, file=stderr)
        print('FAIL')
        sysexit(1)
    except InteractorException:
        print('FAIL')
        raise
    except Exception as exc:
        raise InteractorException(
                "The interactor issued an error! "
                "Please contact the admins. (Also save the script's output and send them to the admins.)") from exc
    else:
        print(
            "The interaction has finished. "
            f"In this interaction, we have {s = !s} (≈ {float(s):.5f}) and {a = !s} (≈ {float(a):.5f}). "
            f"Thus, the corresponding score is {float(get_score(s, a)):.2f}. "
            "Note that I didn't check whether the answers were correct!",
            file=stderr)

if __name__ == '__main__':
    main()

### @@ }