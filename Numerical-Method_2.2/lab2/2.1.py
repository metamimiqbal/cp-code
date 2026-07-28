import math

def bisection(f,a,b,eps = 1e-4,mx = 100):
    print(f"{'n':<5}{'a':<12}{'b':<12}{'xn':<12}{'f(xn)':<15}new interval")

    for i in range (1,mx+1,1):
        x = (a+b)/2
        fx = f(x)

        if(f(a)*fx<0):
            na,nb = a,x
            s = f"[{a:.6f}, {x:.6f}]"
            b = x
        else:
            na,nb = x,b
            s = f"[{x:.6f}, {b:.6f}]"
            a = x

        print(f"{i:<5}{na:<12.6f}{nb:<12.6f}{x:<12.6f}{fx:<15.6f}{s}")

        if(abs(fx)==0 or (nb-na)/2<eps):
            print("\nAnswer =",round(x,4))
            print("")
            return


def ex1():
    print("Exercise 1")
    print("x^3 - x - 1 = 0\n")

    def f(x):
        return x**3-x-1

    bisection(f,1,2)


def ex2():
    print("Exercise 2")
    print("x^3 - 2x - 5 = 0\n")

    def f(x):
        return x**3-2*x-5

    bisection(f,2,3)

    print("Answer (3 d.p.) = 2.094")
    print("")


def ex3():
    print("Exercise 3")
    print("x^3 + x^2 + x + 7 = 0\n")

    def f(x):
        return x**3+x**2+x+7

    bisection(f,-3,-2)

    print("Answer (3 d.p.) = -2.000")
    print("")


def ex4():
    print("Exercise 4")
    print("x^3 - 4x - 9 = 0\n")

    def f(x):
        return x**3-4*x-9

    bisection(f,2,3)


def ex5():
    print("Exercise 5")
    print("x^4 - x - 10 = 0\n")

    def f(x):
        return x**4-x-10

    bisection(f,1,2)


def ex6():
    print("Exercise 6")
    print("x - cos(x) = 0\n")

    def f(x):
        return x-math.cos(x)

    bisection(f,0,1)


def ex7():
    print("Exercise 7")
    print("x*e^x - 1 = 0\n")

    def f(x):
        return x*math.exp(x)-1

    bisection(f,0,1)


def ex8():
    print("Exercise 8")
    print("3x - cos(x) - 1 = 0\n")

    def f(x):
        return 3*x-math.cos(x)-1

    bisection(f,0,1)


def ex9():
    print("Exercise 9")
    print("e^x - 3x = 0 (First Root)\n")

    def f(x):
        return math.exp(x)-3*x

    bisection(f,0,1)

    print("Second Root\n")
    bisection(f,1,2)


def ex10():
    print("Exercise 10")
    print("x*sin(x) - 1 = 0\n")

    def f(x):
        return x*math.sin(x)-1

    bisection(f,1,2)


def ex11():
    print("Exercise 11")
    print("ln(x) - x + 2 = 0\n")

    def f(x):
        return math.log(x)-x+2

    bisection(f,3,4)


def ex12():
    print("Exercise 12")
    print("h^3 - 3h^2 + 2.4 = 0\n")

    def f(h):
        return h**3-3*h**2+2.4

    bisection(f,1,2)

    print("Answer (3 d.p.) =",round(1.070,3))
    print("")


def main():
    ex1()
    ex2()
    ex3()
    ex4()
    ex5()
    ex6()
    ex7()
    ex8()
    ex8()
    ex9()
    ex10()
    ex11()
    ex12()


main()

