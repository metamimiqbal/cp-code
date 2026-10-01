import math

# assuming no. of iternation n = 10 for the whole codebase.

def f(x):
    return x*x*x - 2*x  - 5
def df(x):
    return 3*x**2 - 2

ephsilon = 10**-3


def bisection():
    a = 1
    b = 2
    c = None
    for i in range(10):
        c = (a+b)/2
        if f(c) == 0 or (b-a)/2 < ephsilon:
            return c
        if f(a)*f(c) < 0:
            b = c
        else: # f(b)*f(c) < 0
            a = c
    return c

def regularFalsi():
    # input: a, b, f(x)
    a = 1
    b = 2
    c = None
    for i in range(10):
        c = (a*f(b) - b*f(a))/(f(b)-f(a))
        if f(c) == 0 or (b-a)/2 < ephsilon:
            return c
        if f(a)*f(c) < 0:
            b = c
        else:
            a = c
    return c

def phi(x):
    return 1/math.sqrt(1+x)

def fixedPointIteration():
    # input: x0, x1, phi(x)
    x0 = 0.75
    x1 = None
    for i in range(10):
        x1 = phi(x0)
        if (x1-x0)<ephsilon :
            return x1
        x0 = x1
    return x1


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
def generalizedNewtonRaphson():
    # input: f(x) = df(x) in this code, f'(x), no. of iteration
    x0 = 2
    x1 = None
    p = 2 # the first derivative that's nonzero for the given root, 
    #rule to determine p: keep derivating until the result is nonzero
    for i in range(10):
        if df(x0) == 0 :
            return -1
        x1 = x0 - p*(f(x0)/df(x0))
        if x1-x0 < ephsilon:
            return x1
        x0 = x1
    return x1


def secantMethod():
    x0 = 2
    x1 = 3
    x2 = None
    for i in range(50):
        if f(x1)-f(x0) == 0:
            return -1
        x2 = x1 - ((x1-x0)/(f(x1)-f(x0)))*f(x1)
        if(abs(x2 - x1) < ephsilon): return x2
        x0, x1 = x1, x2
    return x2
# print(secantMethod())
# print(bisection())
# print(regularFalsi())
# print(fixedPointIteration())
# print(generalizedNewtonRaphson())




# Iteration Method for Systems of Nonlinear Equations
def ff(x, y):
    return (3*x*x*y + 7)/10
def gg(x, y):
    return (y**2 + 4)/5 

ephsilon = 10**-3
def IterativeForNonLinearEquations():
    x0 = 0.5
    y0 = 0.5
    for i in range(50):
        x1 = ff(x0, y0)
        y1 = gg(x0, y0)
        if x1-x0 < ephsilon and y1 - y0 < ephsilon:
            return (x1, y1)
        x0, y0 = x1, y1

    return x0, y0

# print(IterativeForNonLinearEquations())
x, y = IterativeForNonLinearEquations()

print(f"{x:0.6f}, {y:0.6f}")
