for _ in range(int(input())):
    s = input()
    hr = int(s[0:2])
    mn = int(s[3:5])
    m = "AM"
    if (hr >= 12):
        m = "PM"
        if (hr > 12):
            hr -= 12
    
    a = str(hr)
    b = str(mn)
    if (len(a) == 1):
        a = '0' + a
    if (len(b) == 1):
        b = '0' + b
    if (a == '00'):
        a = '12'
    print(f"{a}:{b} {m}")