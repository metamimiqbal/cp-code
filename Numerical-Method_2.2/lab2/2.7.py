import math

def secant(f,x0,x1,eps = 1e-4,mx = 100):
    print(f"{'n':<5}{'x0':<12}{'x1':<12}{'x2':<12}{'f(x2)':<15}")

    for i in range (1,mx+1,1):
        f0 = f(x0)
        f1 = f(x1)

        x2 = (x0*f1-x1*f0)/(f1-f0)
        f2 = f(x2)

        print(f"{i:<5}{x0:<12.6f}{x1:<12.6f}{x2:<12.6f}{f2:<15.6f}")

        if(abs(x2-x1)<eps):
            print("\nAnswer =",round(x2,4))
            print("")
            return

        x0 = x1
        x1 = x2

def ex1():
    print("Exercise 1")
    print("x^3 - 2x - 5 = 0\n")

    def f(x):
        return x**3-2*x-5

    secant(f,2,3)

def ex2():
    print("Exercise 2")
    print("x*e^x - 1 = 0\n")

    def f(x):
        return x*math.exp(x)-1

    secant(f,0,1)

def ex3():
    print("Exercise 3")
    print("x^3 - x - 1 = 0\n")

    def f(x):
        return x**3-x-1

    secant(f,1,2)

def ex4():
    print("Exercise 4")
    print("cos(x) - x*e^x = 0\n")

    def f(x):
        return math.cos(x)-x*math.exp(x)

    secant(f,0,1)

def ex5():
    print("Exercise 5")
    print("x - cos(x) = 0\n")

    def f(x):
        return x-math.cos(x)

    secant(f,0,1)

def ex6():
    print("Exercise 6")
    print("x^2.2 - 69 = 0\n")

    def f(x):
        return x**2.2-69

    secant(f,5,8)

def ex7():
    print("Exercise 7")
    print("x^4 - x - 10 = 0\n")

    def f(x):
        return x**4-x-10

    secant(f,1,2)

def ex8():
    print("Exercise 8")
    print("e^x - 3x = 0\n")

    def f(x):
        return math.exp(x)-3*x

    secant(f,0,1)

    print("Second Root\n")
    secant(f,1,2)

def ex9():
    print("Exercise 9")
    print("ln(x) - x + 2 = 0\n")

    def f(x):
        return math.log(x)-x+2

    secant(f,3,4)

def ex10():
    print("Exercise 10")
    print("x*sin(x) - 1 = 0\n")

    def f(x):
        return x*math.sin(x)-1

    secant(f,1,2)

def ex11():
    print("Exercise 11")
    print("tan(x) - x = 0\n")

    def f(x):
        return math.tan(x)-x

    secant(f,4.4,4.6)

def ex12():
    print("Exercise 12")
    print("Colebrook Equation\n")

    def f(x):
        return (1/math.sqrt(x))+2*math.log10((10**-4/3.7)+(2.51/(10**5*math.sqrt(x))))

    secant(f,0.01,0.03)

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