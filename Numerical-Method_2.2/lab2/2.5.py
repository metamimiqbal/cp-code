import math


def newton(f,df,x,eps = 1e-5,mx = 100):
    print(f'{"n":<5}{"xn":<12}{"f(xn)":<12}{"f\'(xn)":<12}{"x(n+1)":<12}')

    for i in range (mx+1):
        fx = f(x)
        dfx = df(x)

        if(dfx==0):
            return

        xn = x-fx/dfx

        print(f"{i:<5}{x:<12.6f}{fx:<12.6f}{dfx:<12.6f}{xn:<12.6f}")

        if(abs(xn-x)<eps):
            print("\nAnswer =",round(xn,4))
            print("")
            return xn

        x = xn

    return x


def ex1():
    print("Exercise 1")
    print("x^3 - 2x - 5 = 0, x0 = 2\n")

    def f(x):
        return x**3-2*x-5

    def df(x):
        return 3*x**2-2

    newton(f,df,2)


def ex2():
    print("Exercise 2")
    print("x sin(x) + cos(x) = 0, x0 = π\n")

    def f(x):
        return x*math.sin(x)+math.cos(x)

    def df(x):
        return x*math.cos(x)

    newton(f,df,math.pi)


def ex3():
    print("Exercise 3")
    print("x e^x - 1 = 0, x0 = 1\n")

    def f(x):
        return x*math.exp(x)-1

    def df(x):
        return math.exp(x)*(x+1)

    newton(f,df,1)


def ex4():
    print("Exercise 4")
    print("sin(x) = x/2, x0 = π/2\n")

    def f(x):
        return math.sin(x)-x/2

    def df(x):
        return math.cos(x)-1/2

    newton(f,df,math.pi/2)


def ex5():
    print("Exercise 5")
    print("4e^(-x) sin(x) - 1 = 0, x0 = 0.2\n")

    def f(x):
        return 4*math.exp(-x)*math.sin(x)-1

    def df(x):
        return 4*math.exp(-x)*(math.cos(x)-math.sin(x))

    newton(f,df,0.2)


def ex6():
    print("Exercise 6")
    print("x^3 - x - 1 = 0, x0 = 1.5\n")

    def f(x):
        return x**3-x-1

    def df(x):
        return 3*x**2-1

    newton(f,df,1.5)


def ex7():
    print("Exercise 7")
    print("cos(x) - x e^x = 0, x0 = 0.5\n")

    def f(x):
        return math.cos(x)-x*math.exp(x)

    def df(x):
        return -math.sin(x)-math.exp(x)*(x+1)

    newton(f,df,0.5)


def ex8():
    print("Exercise 8")
    print("x^4 - x - 10 = 0, x0 = 2\n")

    def f(x):
        return x**4-x-10

    def df(x):
        return 4*x**3-1

    newton(f,df,2)


def ex9():
    print("Exercise 9")
    print("e^x - 3x = 0, x0 = 0.5 and x0 = 1.5\n")

    def f(x):
        return math.exp(x)-3*x

    def df(x):
        return math.exp(x)-3

    print("First Root")
    newton(f,df,0.5)

    print("Second Root")
    newton(f,df,1.5)


def ex10():
    print("Exercise 10")
    print("tan(x) - x = 0, x0 = 4.5\n")

    def f(x):
        return math.tan(x)-x

    def df(x):
        return 1/(math.cos(x)**2)-1

    newton(f,df,4.5)


def ex11():
    print("Exercise 11")
    print("Compute sqrt(24.5) via x^2 - 24.5 = 0, x0 = 5\n")

    def f(x):
        return x**2-24.5

    def df(x):
        return 2*x

    newton(f,df,5)


def ex12():
    print("Exercise 12")
    print("Compute cuberoot(17) via x^3 - 17 = 0, x0 = 2.5\n")

    def f(x):
        return x**3-17

    def df(x):
        return 3*x**2

    newton(f,df,2.5)


def main():
    ex1()
    ex2()
    ex3()
    ex4()
    ex5()
    ex6()
    ex7()
    ex8()
    ex9()
    ex10()
    ex11()
    ex12()


main()