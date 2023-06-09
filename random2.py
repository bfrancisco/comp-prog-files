n = 3

def r(s):
  if len(s) == n:
    print(s)
    return
  
  
  r(s+"1")
  if (not s  or (s and s[-1] != "2")):
    r(s+"2")
  r(s+"3")


r("")
