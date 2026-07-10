import math

print("Exercise-1")
def f(v):
    return 9.8-(12.5/68.1)*v

def calc(h):
    t = 10
    t_initial = 0
    v = 0

    while t_initial <= t:
        v = v + f(v) * h
        t_initial += h
    
    return t, v

print("Case-1: h = ", 1)
print(calc(1))
print("Case-2: h = ", .5)
print(calc(.5))
print("Case-2: h = ", .25)
print(calc(.25))



print("Exercise-2")
def ff(v):
    return -v

def fex(x):
    return math.e**-x

def calc2(h):
    t = 1
    t_initial = 0
    v = 0

    while t_initial <= t:
        v = v + ff(v) * h
        t_initial += h
    
    return v

print(calc2(0.1), fex(calc2(0.1)))


