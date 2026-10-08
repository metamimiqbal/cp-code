#learning:
grid = [["2d" for _ in range(3)] for _ in range(2)]

for i in range(2):
    for j in range(3):
        print(grid[i][j], end = " ")
    print()


print(f"Number of row: {len(grid)}")
print(f"Number of column: {len(grid[0])}")


# Creates n empty rows: [[], [], ..., []]: grid = [[] for _ in range(n)]


#use case:
n = 5
D = [[] for _ in range(n)]

x = [2, 3, 4, 5]

def F(xx):
    return xx**2

for i in range(len(x)):
    D[0].append(F(x[i]))

for i in range(len(D[0])):
    print(D[0][i], end = " ")
print()


# forward difference table
x = [-1, 0, 1, 2, 3, 4]

def f(xx):
    return xx**3 - 3*xx**2 + 5*xx - 7

D = [[] for _ in range(len(x))]

for i in range(len(x)):
    D[0].append(f(x[i]))

n = len(x)
for k in range(1, n) :
    for i in range(len(D[k-1])-1):
        D[k].append(D[k-1][i+1]-D[k-1][i])


for i in range(len(D)):
    for j in range(len(D[i])):
        print(D[i][j], end = " ")
    print()