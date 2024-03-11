from sympy import Matrix

A = Matrix([
    [1,1,2,8],
    [-1,-2,3,1],
    [3,-7,4,10],
])
A = A.rref(pivots=False)

print(A)