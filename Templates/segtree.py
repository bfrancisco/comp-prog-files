def op(x, y):
    # you change this
    return x + y

class SegTree:
    def __init__(self, a, L, R, op):
        self.L = L
        self.R = R
        if R - L == 1:
            self.value = a[L]
        else:
            M = (L+R) // 2
            self.left = SegTree(a, L, M)
            self.right = SegTree(a, M, R)
            self.value = op(self.left.value, self.right.value)

    def build(self, a)
        