from sympy import Matrix

A = Matrix([
    [-5, -15, -18],
    [26, 45, 87],
    [40, 80, 136]
])
E = Matrix([
    [-1],
    [1],
    [0],
    ]
)
# A = A.rref(pivots=False)

print(A*E)

A = Matrix()