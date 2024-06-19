n = int(input())
s = input()

if (n%2):
    print("No")
    exit()

print("Yes" if s[:n//2] == s[n//2:] else "No")