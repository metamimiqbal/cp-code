def lagrange(x, y):
    X = float(input())
    ans = 0
    for i in range(len(x)):
        term = y[i]

        for j in range(len(x)):
            if i!=j:
                term *= (X-x[j])/(x[i]-x[j])
        ans+=term
    return ans


def f1():
    x = [40, 50, 60, 70, 80, 90]
    y = [184, 204, 226, 250, 276, 304]
    print(lagrange(x, y))

def f2():
    x = [5, 6, 9, 11]
    y = [12, 13, 14, 16]
    print(lagrange(x, y))


def f3():
    x = [0, 1, 2, 5]
    y = [2, 3, 12, 147]
    print(lagrange(x, y))

def f4():
    x = [0, 1, 3, 4]
    y = [-12, 0, 12, 24]
    print(lagrange(x, y))

if __name__ == "__main__":
    f1()
    f2()
    f3()
    f4()