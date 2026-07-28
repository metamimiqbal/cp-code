import math


def newton(f,df,p,x,eps = 1e-5,mx = 100):
    print(f'{"n":<5}{"xn":<12}{"f(xn)":<12}{"f\'(xn)":<12}{"x(n+1)":<12}')

    for i in range (mx+1):
        fx = f(x)
        dfx = df(x)

        if(abs(fx)<eps):
            print(f"{i:<5}{x:<12.6f}{fx:<12.6f}{dfx:<12.6f}{'≈ 0':<12}")
            print("\nAnswer =",round(x,4))
            print("")
            return x

        if(dfx==0):
            return

        xn = x-p*fx/dfx

        print(f"{i:<5}{x:<12.6f}{fx:<12.6f}{dfx:<12.6f}{xn:<12.6f}")

        if(abs(xn-x)<eps):
            print("\nAnswer =",round(xn,4))
            print("")
            return xn

        x = xn

    return x


def ex1():
    print("Exercise 1")
    print("x^3 - x^2 - x + 1 = 0, p = 2, x0 = 0.8\n")

    def f(x):
        return x**3-x**2-x+1

    def df(x):
        return 3*x**2-2*x-1

    newton(f,df,2,0.8)


def ex2():
    print("Exercise 2")
    print("x^3 - 3x + 2 = 0, p = 2, x0 = 1.2\n")

    def f(x):
        return x**3-3*x+2

    def df(x):
        return 3*x**2-3

    newton(f,df,2,1.2)


def ex3():
    print("Exercise 3")
    print("x^3 - 5x^2 + 8x - 4 = 0, p = 2, x0 = 1.8\n")

    def f(x):
        return x**3-5*x**2+8*x-4

    def df(x):
        return 3*x**2-10*x+8

    newton(f,df,2,1.8)


def ex4():
    print("Exercise 4")
    print("x^3 - x^2 - 8x + 12 = 0, p = 2, x0 = 1.8\n")

    def f(x):
        return x**3-x**2-8*x+12

    def df(x):
        return 3*x**2-2*x-8

    newton(f,df,2,1.8)


def ex5():
    print("Exercise 5")
    print("x^3 + 3x^2 + 3x + 1 = 0, p = 3, x0 = -0.7\n")

    def f(x):
        return x**3+3*x**2+3*x+1

    def df(x):
        return 3*x**2+6*x+3

    newton(f,df,3,-0.7)


def ex6():
    print("Exercise 6")
    print("x^3 - 6x^2 + 12x - 8 = 0, p = 3, x0 = 1.7\n")

    def f(x):
        return x**3-6*x**2+12*x-8

    def df(x):
        return 3*x**2-12*x+12

    newton(f,df,3,1.7)


def ex7():
    print("Exercise 7")
    print("x^4 - 4x^3 + 6x^2 - 4x + 1 = 0, p = 4, x0 = 1.3\n")

    def f(x):
        return x**4-4*x**3+6*x**2-4*x+1

    def df(x):
        return 4*x**3-12*x**2+12*x-4

    newton(f,df,4,1.3)


def ex8():
    print("Exercise 8")
    print("x^4 - 2x^2 + 1 = 0, p = 2, x0 = 1.2\n")

    def f(x):
        return x**4-2*x**2+1

    def df(x):
        return 4*x**3-4*x

    newton(f,df,2,1.2)


def ex9():
    print("Exercise 9")
    print("x^4 - 8x^2 + 16 = 0, p = 2, x0 = 1.8\n")

    def f(x):
        return x**4-8*x**2+16

    def df(x):
        return 4*x**3-16*x

    newton(f,df,2,1.8)


def ex10():
    print("Exercise 10")
    print("x^4 + 2x^3 - 3x^2 - 4x + 4 = 0, p = 2, x0 = 0.7\n")

    def f(x):
        return x**4+2*x**3-3*x**2-4*x+4

    def df(x):
        return 4*x**3+6*x**2-6*x-4

    newton(f,df,2,0.7)


def ex11():
    print("Exercise 11")
    print("For Exercise 1, compare ordinary Newton and generalized Newton\n")

    def f(x):
        return x**3-x**2-x+1

    def df(x):
        return 3*x**2-2*x-1

    print("Generalized Newton")
    newton(f,df,2,0.8)

    print("Ordinary Newton")
    newton(f,df,1,0.8)


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


main()

