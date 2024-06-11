db2 = {}
db3 = {}
MX = 10**7 + 1

mxln2 = -1
mxln3 = -1
for x in range(1, MX):
    sq = x*x
    ln = len(str(sq))
    mxln2 = max(mxln2, ln)
    if mxln2 > 40:
        break
    if ln not in db2:
        db2[ln] = [sq]
    else:
        db2[ln].append(sq)
    

# for x in range(1, MX):
#     sq = x*x*x
#     ln = len(str(sq))
#     mxln3 = max(mxln3, ln)
#     if mxln3 > 40:
#         break
#     if ln not in db3:
#         db3[ln] = [sq]
#     else:
#         db3[ln].append(sq)

# for ln, nums in db2.items():
#     print("Size:", ln)
#     for x in nums:
#         print(x, end=" ")
#     print()

multisquare = []
for ln in range(1, mxln2+1):
    pdb = {}
    for num in db2[ln]:
        mset = tuple(sorted(list(str(num))))
        if mset not in pdb:
            pdb[mset] = [num]
        else:
            pdb[mset].append(num)
    for mset, nums in pdb.items():
        if len(nums) == ln:
            multisquare.append(nums)
            break

# multicube = []
# for ln in range(1, mxln3+1):
#     pdb = {}
#     for num in db3[ln]:
#         mset = tuple(sorted(list(str(num))))
#         if mset not in pdb:
#             pdb[mset] = [num]
#         else:
#             pdb[mset].append(num)
#     for mset, nums in pdb.items():
#         if len(nums) == ln:
#             multicube.append(nums)
#             break

# print("SQUARE")
for x in multisquare:
    print(len(x), ':', x)

# print("\nCUBE")
# for x in multicube:
#     print(len(x), ':', x)