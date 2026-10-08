# 6:
def f(x):
    return x**3
x = [1, 2, 3, 4, 5]

D = [[] for _ in range(len(x))]
for i in range(len(x)):
    D[0].append(f(x[i]))

for k in range(1, len(D)):
    for i in range(len(D[k-1])-1):
        D[k].append(D[k-1][i+1]-D[k-1][i])


h = x[1] - x[0]
X = 4.5
u = (X-x[-1])/h

ans = f(x[-1])
l = len(D)
term = 1
for i in range(1, len(D)):
    term *= (u+i-1)/i
    ans += (term*D[i][len(D[i])-1])

print(ans)