def insertion(A):
    n = len(A)
    for i in range(1,n):
        temp = A[i]
        j = i - 1
        while j >= 0 and temp < A[j]:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = temp

def bucket(A):
    n = len(A)
    B = [[] for _ in range(10)]
    for i in range(n):
        B[int(A[i]*n)].append(A[i])
    for i in range(n):
        insertion(B[i])
    C = []
    for i in range(n):
        for x in B[i]:
            C.append(x)
    print(C)

A = [0.78,0.72,0.68,0.52,0.55,0.4,0.91,0.32,0.11,0.09]
bucket(A)