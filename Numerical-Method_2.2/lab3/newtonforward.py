def forward(x, y):
    h = x[1] - x[0]

    X = float(input())
    p = (X - x[0])/h

    D = [y]
    while(len(D[-1]) > 1):
        prev = D[-1]
        nxt = []
        for i in range(len(prev)-1):
            nxt.append(prev[i+1]-prev[i])
        D.append(nxt)


    ans = y[0]
    term = 1
    for k in range(1, len(D)):
        term *= (p-(k-1))/k
        ans += (term * D[k][0])

    return ans


def f1():
    x = [1, 3, 5, 7]
    y = [24, 120, 336, 720]
    print(forward(x, y))

def f2():
    x = [5, 6, 9, 11]
    y = [12, 13, 14, 16]
    print(forward(x, y))


def f3():
    x = [0, 1, 2, 5]
    y = [2, 3, 12, 147]
    print(forward(x, y))

def f4():
    x = [40, 50, 60, 70, 80, 90]
    y = [184, 204, 226, 250, 276, 304]
    print(forward(x, y))


if __name__=="__main__":
    f1()
    f2()
    f3()
    f4()



