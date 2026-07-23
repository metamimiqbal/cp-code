import math

# [ Why So Serious ]


def ex1():
    print("Exercise 1")
    print("e^x about x=0 (4 Terms)\n")

    x = 0.1

    ap = 1+x+x**2/math.factorial(2)+x**3/math.factorial(3)
    tr = math.exp(x)

    r3 = (math.exp(x)*(x**4))/math.factorial(4)

    print("Approximation =",ap)
    print("True Value    =",tr)
    print("Bound R3      =",r3)
    print("True Error    =",abs(tr-ap))
    print()


def ex2():
    print("Exercise 2\n")

    xs = [math.pi/4,math.pi/6]
    x = math.pi/3
    tr = math.cos(x)

    for xi in xs:
        print("Base =",xi)

        print(f"{'Order':<8}{'Estimate':<15}{'Et(%)'}")

        ap = math.cos(xi)

        for n in range(5):

            if(n==0):
                ap = math.cos(xi)

            elif(n==1):
                ap = math.cos(xi)-math.sin(xi)*(x-xi)

            elif(n==2):
                ap = math.cos(xi)-math.sin(xi)*(x-xi)-math.cos(xi)*(x-xi)**2/math.factorial(2)

            elif(n==3):
                ap = math.cos(xi)-math.sin(xi)*(x-xi)-math.cos(xi)*(x-xi)**2/math.factorial(2)+math.sin(xi)*(x-xi)**3/math.factorial(3)

            else:
                ap = math.cos(xi)-math.sin(xi)*(x-xi)-math.cos(xi)*(x-xi)**2/math.factorial(2)+math.sin(xi)*(x-xi)**3/math.factorial(3)+math.cos(xi)*(x-xi)**4/math.factorial(4)

            et = (tr-ap)/tr*100
            print(f"{n:<8}{ap:<15.6f}{et:.4f}")

        print()


def ex3():
    print("Exercise 3\n")

    x = 1.1
    h = x-1

    tr = math.log(x)

    ap = h-h**2/2+h**3/3-h**4/4

    print("Approx =",ap)
    print("True   =",tr)
    print("Error  =",abs(tr-ap))
    print()


def ex4():
    print("Exercise 4\n")

    for x in [3.8,4.2]:

        h = x-4

        ap = 2+h/4-h*h/64+h*h*h/512

        print("sqrt(",x,") =",ap)
        print("True =",math.sqrt(x))
        print()


def ex5():
    print("Exercise 5\n")

    x = 0.5
    tr = math.sin(x)

    sm = 0

    for i in range(20):

        sm += ((-1)**i)*(x**(2*i+1))/math.factorial(2*i+1)

        if(round(sm,4)==round(tr,4)):
            print("Terms Needed =",i+1)
            print("Approx =",sm)
            print()
            break


def ex6():
    print("Exercise 6\n")

    print("f(x)=x^3-2x+1 is a polynomial of degree 3.")
    print("Therefore Taylor series of order 3 is exact.\n")


def ex7():
    print("Exercise 7\n")

    x = 0.2

    ap = 1+x+x*x/2

    tr = math.exp(x)

    r2 = math.exp(x)*(x**3)/math.factorial(3)

    print("Approx =",ap)
    print("True   =",tr)
    print("Estimated Truncation Error =",r2)
    print("Actual Error =",abs(tr-ap))
    print()


def ex8():
    print("Exercise 8\n")

    x = 0.2

    ap = x+x**3/3+2*x**5/15

    print("Approx =",ap)
    print("True   =",math.tan(x))
    print()


def ex9():
    print("Exercise 9\n")

    print("Forward Difference Formula:")
    print("f'(x) ≈ (f(x+h)-f(x))/h")
    print("Error Order : O(h)\n")


def ex10():
    print("Exercise 10\n")

    x = 0.05

    ap = 1+x/2-x*x/8+x**3/16

    print("Approx =",ap)
    print("True   =",math.sqrt(1.05))
    print()


def ex11():
    print("Exercise 11\n")

    xi = math.pi/4
    x = math.pi/3

    ap = math.cos(xi)-math.sin(xi)*(x-xi)-math.cos(xi)*(x-xi)**2/2

    tr = math.cos(x)

    rn = abs(math.sin(xi)*(x-xi)**3/math.factorial(3))

    print("Estimated R2 =",rn)
    print("Actual Error =",abs(tr-ap))
    print()


def ex12():
    print("Exercise 12\n")

    print(f"{'x':<8}{'1st':<12}{'2nd':<12}{'3rd'}")

    x = 0

    while(x<=1.0001):

        p1 = 1+x
        p2 = 1+x+x*x/2
        p3 = 1+x+x*x/2+x*x*x/6

        print(f"{x:<8.2f}{p1:<12.6f}{p2:<12.6f}{p3:.6f}")

        x += 0.2

    print()


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