# Lagrange's Interpolation Formula

# x = 300, 304, 305, 307 and y = log10(x), find log10(301)
x = [300, 304, 305, 307]
y = [2.4771, 2.4829, 2.4843, 2.4871]

X = 301

def lagrange():
    # input: x[0..n], y[0..n], X
    n = len(x)
    sum = 0
    for i in range(n):
        L = 1
        for j in range(n):
            if j != i:
                L = L*(X-x[j])/(x[i]-x[j])
        sum += L*y[i]
    return sum

ans = lagrange()

print(f"{ans:0.4f}")