# uhllhw vymyrht ht suv hg dkh ehrydyma ywdasatr l nwv m yr n uhllhw vymyrht hg l nwv m dfnd yr standat dfnw nwo hdfat uhllhw vymyrht hg l nwv m. Eht azalech

LETS = list("abcdefghijklmnopqrstuvwxyz")
ALPHA = set(LETS)
ss = input().lower()

db = {char : char for char in LETS}
for sh in range(26):
    print("Shift:", sh)
    for i in range(26):
        db[LETS[i]] = LETS[(i + sh) % 26]
    
    for ch in ss:
        if ch not in ALPHA:
            print(ch, end='')
        else:
            print(db[ch], end='')
    
    print()
    input()

