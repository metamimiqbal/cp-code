def f(x):
    return x**4 - x - 10

def df(x):
    return 4*x**3 - 1

ephsilon = 10**-4

def newtonRaphson():
    # input: f(x) = df(x) in this code, f'(x), no. of iteration
    x0 = 2
    x1 = None
    for i in range(10):
        if df(x0) == 0 :
            return -1
        x1 = x0 - f(x0)/df(x0)
        if x1-x0 < ephsilon:
            return x1
        x0 = x1
    return x1