import math


def aitken(phi,x,eps = 1e-4,mx = 100):
    print(f"{'n':<5}{'x1':<12}{'x2':<12}{'x3':<12}{'xhat':<12}")

    for i in range (1,mx+1,1):
        x1 = x
        x2 = phi(x1)
        x3 = phi(x2)

        d1 = x2-x1
        d2 = x3-2*x2+x1

        if(abs(d2)<1e-15):
            xh = x3
        else:
            xh = x3-(x3-x2)**2/d2

        print(f"{i:<5}{x1:<12.6f}{x2:<12.6f}{x3:<12.6f}{xh:<12.6f}")

        if(abs(xh-x1)<eps):
            print("\nAnswer =",round(xh,4))
            print("")
            return xh,i

        x = xh

    return x,mx


def plain(phi,x,eps = 1e-4,mx = 100):
    for i in range (1,mx+1,1):
        xn = phi(x)

        if(abs(xn-x)<eps):
            return xn,i

        x = xn

    return x,mx


def ex1():
    print("Exercise 1")
    print("φ(x) = 1/2(3 + cos(x)), x0 = 1.5\n")

    def f(x):
        return (3+math.cos(x))/2

    aitken(f,1.5)
    print("")


def ex2():
    print("Exercise 2")
    print("φ(x) = e^(-x), x0 = 0.5\n")

    def f(x):
        return math.exp(-x)

    aitken(f,0.5)
    print("")


def ex3():
    print("Exercise 3")
    print("φ(x) = cos(x), x0 = 0.5\n")

    def f(x):
        return math.cos(x)

    aitken(f,0.5)
    print("")


def ex4():
    print("Exercise 4")
    print("φ(x) = 1/sqrt(1+x), x0 = 0.75\n")

    def f(x):
        return 1/math.sqrt(1+x)

    aitken(f,0.75)
    print("")


def ex5():
    print("Exercise 5")
    print("φ(x) = sqrt(x+3), x0 = 2\n")

    def f(x):
        return math.sqrt(x+3)

    aitken(f,2)
    print("")


def ex6():
    print("Exercise 6")
    print("φ(x) = 1/2 sqrt(10-x^3), x0 = 1.5\n")

    def f(x):
        return 0.5*math.sqrt(10-x**3)

    aitken(f,1.5)
    print("")


def ex7():
    print("Exercise 7")
    print("φ(x) = 1 + sin(x)/10, x0 = 1\n")

    def f(x):
        return 1+math.sin(x)/10

    aitken(f,1)
    print("")


def ex8():
    print("Exercise 8")
    print("φ(x) = (2-x^2)^(1/3), x0 = 0.8\n")

    def f(x):
        y = 2-x**2
        return math.copysign(abs(y)**(1/3),y)

    aitken(f,0.8)
    print("")


def ex9():
    print("Exercise 9")
    print("Given iterates: 0.6, 0.69, 0.737\n")

    x1 = 0.6
    x2 = 0.69
    x3 = 0.737

    d2 = x3-2*x2+x1
    xh = x3-(x3-x2)**2/d2

    print(f"{'x1':<12}{'x2':<12}{'x3':<12}{'xhat':<12}")
    print(f"{x1:<12.6f}{x2:<12.6f}{x3:<12.6f}{xh:<12.6f}")
    print("\nAnswer =",round(xh,4))
    print("")


def ex10():
    print("Exercise 10")
    print("Given iterates: 1.0, 0.9, 0.832\n")

    x1 = 1.0
    x2 = 0.9
    x3 = 0.832

    d2 = x3-2*x2+x1
    xh = x3-(x3-x2)**2/d2

    print(f"{'x1':<12}{'x2':<12}{'x3':<12}{'xhat':<12}")
    print(f"{x1:<12.6f}{x2:<12.6f}{x3:<12.6f}{xh:<12.6f}")
    print("\nAnswer =",round(xh,4))
    print("")


def ex11():
    print("Exercise 11")
    print("Compare plain iteration and Aitken's Δ² acceleration for Exercise 3\n")

    def f(x):
        return math.cos(x)

    x1,c1 = plain(f,0.5)
    x2,c2 = aitken(f,0.5)

    print("Comparison")
    print("Plain iteration =",round(x1,6),"after",c1,"iterations")
    print("Aitken estimate  =",round(x2,6),"after",c2,"iterations")

    if(c2!=0):
        print("Speed-up factor =",round(c1/c2,4))

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
    ex9()
    ex10()
    ex11()


main()