sec = int(input("Seconds: "))
day = sec//(24*60*60)
sec -= day*(24*60*60)
hour = sec//(60*60)
sec -= hour*(60*60)
mint = sec//60
sec -= mint*60

print(day, hour, mint, sec)
