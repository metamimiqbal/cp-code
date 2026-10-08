import math

# Ramanujan's Method (Smallest Root)

# assuming no. of iternation M = 50 for the whole codebase.

# f(x) = 1 - x + x^2/(2!)^2 - x^3/(3!)^2 + ... = 0
# f(x) = 1 - (a1 x + a2 x^2 + ...), where a_k = (-1)^(k+1) / (k!)^2
M = 50
a = [(-1)**(k+1)/math.factorial(k)**2 for k in range(1, M+1)]

ephsilon = 10**-6

def ramanujan():
    # input: a1, a2, ..., no. of terms M, ephsilon
    b = [0.0 for _ in range(M+1)]
    b[1] = 1

    for k in range(2, M+1):
        for j in range(1, k):
            if j-1 < len(a): # a_j = 0 beyond the given coefficients
                b[k] += a[j-1]*b[k-j]

    c = [0.0 for _ in range(M+1)]
    for i in range(2, M+1):
        if b[i] == 0:
            return -1
        c[i] = b[i-1]/b[i]
        if i > 2 and abs(c[i]-c[i-1]) < ephsilon: # c1 doesn't exist, so start checking from i = 3
            return c[i]
    return c[M]

ans = ramanujan()

print(f"{ans:0.4f}")