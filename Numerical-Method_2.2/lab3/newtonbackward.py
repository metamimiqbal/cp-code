def backward(x, y):
    h = x[1] - x[0]
    X = float(input())
    p = (X - x[-1])/h 

    D = [y]
    while(len(D[-1]) > 1):
        jew = D[-1]
        temp = []
        for i in range(len(jew)-1):
            temp.append(jew[i+1]-jew[i])
        D.append(temp)
    ans = D[0][-1]
    term = 1
    for i in range(1, len(D)):
        term *= (p+(i-1))/i
        ans += term*D[i][-1]
    return ans

def f1():
    x = [40,50,60,70,80,90]
    y = [184,204,226,250,276,304]
    print(backward(x, y))

def f2():
    x = [5, 6, 9, 11]
    y = [12, 13, 14, 16]
    print(backward(x, y))


def f3():
    x = [0, 1, 2, 5]
    y = [2, 3, 12, 147]
    print(backward(x, y))


if __name__ == "__main__":
    f1()
    f2()
    f3()