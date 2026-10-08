def f(x):
    return x**4 - x - 10

def dif_of_f(x):
    return 4*x**3 - 1


ephsilon = 10**-9


print("xn+1      xn      f(xn)      f'(xn)")
def printTable(x1, x0, fun, dfun):
    print(f"{x0 :0.4f} {fun :0.4f} {dfun: 0.4f}   {x1: 0.4f}")


def NewtonRaphson():
    x0 = 2
    x1 = None
    for i in range(50):
        if dif_of_f(x0) == 0:
            print("Nai")
            return -1
        x1 = x0 - f(x0)/dif_of_f(x0)
        printTable(x1, x0, f(x0), dif_of_f(x0))
        if abs(x1-x0) < ephsilon:
            return x1
        x0 = x1
    return x1

print(f"{NewtonRaphson():0.4f}")


