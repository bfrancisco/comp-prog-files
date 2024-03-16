from math import sqrt

x1,y1 = [int(x) for x in input().split()]
x2,y2 = [int(x) for x in input().split()]
x3,y3 = [int(x) for x in input().split()]
x4,y4 = [int(x) for x in input().split()]
 
def dist(x1,y1,x2,y2):
    x = pow((x2-x1), 2)
    y = pow((y2-y1), 2)
    return sqrt(x+y)
 
def parl(x1,y1,x2,y2,x3,y3,x4,y4):
    return (y2-y1)*(x4-x3) == (y4-y3)*(x2-x1)
    # t = (y2-y1)*(x4-x3) - (y4-y3)*(x2-x1)
    # if t == 0:
    #     return True
    # else:
    #     return False

def equal(a, b):
    return abs(a-b) < 0.00000000000000001
 
sides = []
sides.append(dist(x1,y1,x2,y2))
sides.append(dist(x2,y2,x3,y3))
sides.append(dist(x3,y3,x4,y4))
sides.append(dist(x4,y4,x1,y1))
 
if equal(sides[0], sides[1]) and equal(sides[0], sides[2]) and equal(sides[0], sides[3]):
    if equal(dist(x1,y1,x3,y3), dist(x2,y2,x4,y4)):
        print("square")
    else:
        print("rhombus")
 
elif equal(dist(x1, y1, x2, y2), dist(x3, y3, x4, y4)) and equal(dist(x2, y2, x3, y3), dist(x4, y4, x1, y1)):
    if equal(dist(x1,y1,x3,y3), dist(x2,y2,x4,y4)):
        print("rectangle")
    else:
        print("parallelogram")
elif parl(x1,y1,x2,y2,x3,y3,x4,y4) or parl(x2,y2,x3,y3,x4,y4,x1,y1):
    print("trapezium")
elif (equal(dist(x1, y1, x2, y2), dist(x2, y2, x3, y3)) and equal(dist(x3, y3, x4, y4), dist(x4, y4, x1, y1))) or (equal(dist(x2, y2, x3, y3), dist(x3, y3, x4, y4)) and equal(dist(x4, y4, x1, y1), dist(x1, y1, x2, y2))):
    print("kite")
else:
    print("none")