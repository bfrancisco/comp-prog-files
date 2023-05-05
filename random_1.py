def MaxDist(A, N):
 
    # List to store maximum and
    # minimum of all the four forms
    V = [0 for i in range(N)]
    V1 = [0 for i in range(N)]
 
    for i in range(N):
        V[i] = A[i][0] + A[i][1]
        V1[i] = A[i][0] - A[i][1]
    
    
    # Sorting both the vectors
    V.sort()
    V1.sort()
 
    maximum = max(V[-1] - V[0],
                  V1[-1] - V1[0])
    print(*V)
    print(*V1)
    
    print(maximum)
 
 
# Driver code
if __name__ == "__main__":
 
    N = int(input())
 
    # Given Co-ordinates
    A = []
    for i in range(N):
        a,b = map(int, input().split())
        A.append([a,b])
 
    # Function call
    MaxDist(A, N)