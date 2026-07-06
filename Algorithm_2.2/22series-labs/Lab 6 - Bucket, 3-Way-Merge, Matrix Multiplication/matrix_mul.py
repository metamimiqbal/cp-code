A = [
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ]
B = [
        [1,2,3],
        [4,5,6],
        [7,8,9]
    ]
n = 3
M = [[[] for _ in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        M[i][j] = 0
        for k in range(n):
            M[i][j] += A[i][k] * B[k][j]
print(M)