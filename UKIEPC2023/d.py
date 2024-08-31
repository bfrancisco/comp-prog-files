Num_couriers = int(input())
Courier_Strength = [int(i) for i in input().split()]

Courier_Strength.sort()

# def grouper(StrengthSorter):
#     if len(StrengthSorter) == 0:
    
#     Stuff = [StrengthSorter[0], StrengthSorter[-1], StrengthSorter[-2]]
    

#     return

[2,3,4,5,6]
Answer = 0
for i in range(Num_couriers // 3):
    Answer += int(Courier_Strength[-2])
    Courier_Strength.pop(-1)
    Courier_Strength.pop(-1)
    
    # print(Courier_Strength)
print(Answer)


