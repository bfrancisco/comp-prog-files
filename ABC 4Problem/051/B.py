a,b,c,d = map(int, input().split())
x, y = c-a, d-b
print("U"*y, "R"*x, "D"*y, "L"*(x+1), "U"*(y+1), "R"*(x+1), "DR", "D"*(y+1), "L"*(x+1), "U", sep='')