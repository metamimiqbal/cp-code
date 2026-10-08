x = [1, 2, 3, 4, 5]

def f(x):
    return x**3

y = []
D = [[] for _ in range(len(x))]
for i in range(len(x)):
    val = f(x[i])
    y.append(val)
    D[0].append(val)

for k in range(1, len(y)):
    for i in range(len(D[k-1])-1):
        D[k].append(D[k-1][i+1]-D[k-1][i])


# forward:
yy = []
for i in range(len(D)):
    yy.append(D[i][0])

X = 1.5
h = x[1]-x[0]
u = (X-x[0])/h

ans = f(x[0])
p = 1
for i in range(1, len(D)):
    p = p*(u-i+1)/i
    ans += (p*yy[i])

print(ans)

# for i in range(len(D)):
#     for j in range(len(D[i])):
#         print(D[i][j], end = " ")
#     print()

