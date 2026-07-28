import math

def regula(f,a,b,eps=1e-4,n=100):
    print(f"{'n':<5}{'a':<12}{'b':<12}{'xn':<12}{'f(xn)':<15}")

    for i in range(1,n+1):
        fa = f(a)
        fb = f(b)

        x = (a*fb-b*fa)/(fb-fa)
        fx = f(x)

        print(f"{i:<5}{a:<12.6f}{b:<12.6f}{x:<12.6f}{fx:<15.6f}")

        if(abs(fx)<eps):
            print("\nAnswer =",round(x,4))
            print()
            return

        if(fa*fx<0):
            b = x
        else:
            a = x


def ex1():
    print("Exercise 1")
    print("x^3 - 2x - 5 = 0\n")

    def f(x):
        return x**3-2*x-5

    regula(f,2,3)


def ex2():
    print("Exercise 2")
    print("x^2 - 69 = 0\n")

    def f(x):
        return x**2-69

    regula(f,5,8)


def ex3():
    print("Exercise 3")
    print("2x - log10(x) - 7 = 0\n")

    def f(x):
        return 2*x-math.log10(x)-7

    regula(f,3,4)


def ex4():
    print("Exercise 4")
    print("4e^(-x)sin(x) - 1 = 0\n")

    def f(x):
        return 4*math.exp(-x)*math.sin(x)-1

    regula(f,0,0.5)


def ex5():
    print("Exercise 5")
    print("x^3 - x - 1 = 0\n")

    def f(x):
        return x**3-x-1

    regula(f,1,2)


def ex6():
    print("Exercise 6")
    print("cos(x) - xe^x = 0\n")

    def f(x):
        return math.cos(x)-x*math.exp(x)

    regula(f,0,1)


def ex7():
    print("Exercise 7")
    print("xlog10(x) - 1.2 = 0\n")

    def f(x):
        return x*math.log10(x)-1.2

    regula(f,2,3)


def ex8():
    print("Exercise 8")
    print("x^3 + x^2 - 3x - 3 = 0\n")

    def f(x):
        return x**3+x**2-3*x-3

    regula(f,1,2)


def ex9():
    print("Exercise 9")
    print("ln(x) - x + 2 = 0\n")

    def f(x):
        return math.log(x)-x+2

    regula(f,3,4)


def ex10():
    print("Exercise 10")
    print("x - e^(-x) = 0\n")

    def f(x):
        return x-math.exp(-x)

    regula(f,0,1)


def ex11():
    print("Exercise 11")
    print("e^(-x) - sin(x) = 0\n")

    def f(x):
        return math.exp(-x)-math.sin(x)

    regula(f,0,1)


def ex12():
    print("Exercise 12")
    print("csinh(4/c) - 5 = 0\n")

    def f(c):
        return c*math.sinh(4/c)-5

    regula(f,3,4)


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