n = int(input())

a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

x = min(b) - max(a) + 1
print(max(0, x))