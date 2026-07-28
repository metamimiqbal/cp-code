import math

def fixed(phi,x0,k=1,eps=1e-4,n=100):
    print(f"{'n':<5}{'xn':<15}{'xn+1':<15}{'|xn+1-xn|'}")

    for i in range(n):
        x1 = phi(x0)
        d = abs(x1-x0)

        print(f"{i:<5}{x0:<15.6f}{x1:<15.6f}{d:.6f}")

        if(d<eps*(1-k)/k):
            print("\nAnswer =",round(x1,4))
            print()
            return

        x0 = x1


def ex1():
    print("Exercise 1")
    print("x^3 + x^2 - 1 = 0\n")

    def phi(x):
        return 1/math.sqrt(1+x)

    fixed(phi,0.75,0.2)


def ex2():
    print("Exercise 2")
    print("2x - 3 = cos(x)\n")

    def phi(x):
        return (3+math.cos(x))/2

    fixed(phi,1.5,0.5)


def ex3():
    print("Exercise 3")
    print("xe^x = 1\n")

    def phi(x):
        return math.exp(-x)

    fixed(phi,0.5,0.57)


def ex4():
    print("Exercise 4")
    print("sin(x) = 10(x-1)\n")

    def phi(x):
        return 1+math.sin(x)/10

    fixed(phi,1,0.1)




def ex5():
    print("Exercise 5")
    print("x = cos(x)\n")

    def phi(x):
        return math.cos(x)

    fixed(phi,0.5,0.85)


def ex6():
    print("Exercise 6")
    print("x^2 - x - 3 = 0\n")

    def phi(x):
        return math.sqrt(x+3)

    fixed(phi,2,0.30)


def ex7():
    print("Exercise 7")
    print("x^2 - 2x - 5 = 0\n")

    def phi(x):
        return math.sqrt(2*x+5)

    fixed(phi,3,0.42)


def ex8():
    print("Exercise 8")
    print("x^3 + 4x^2 - 10 = 0\n")

    def phi(x):
        return 0.5*math.sqrt(10-x**3)

    fixed(phi,1.5,0.51)




def ex9():
    print("Exercise 9")
    print("x^3 - 3x + 1 = 0\n")

    def phi(x):
        return (x**3+1)/3

    fixed(phi,0.5,0.25)


def ex10():
    print("Exercise 10")
    print("e^(-x) = x\n")

    def phi(x):
        return math.exp(-x)

    fixed(phi,0.5,0.57)


def ex11():
    print("Exercise 11")
    print("tan(x) = x\n")

    def phi(x):
        return math.atan(x)

    fixed(phi,4.5,0.05)


def ex12():
    print("Exercise 12")
    print()

    print("Approximate k values")
    print("1 -> 0.20")
    print("2 -> 0.50")
    print("3 -> 0.57")
    print("4 -> 0.10")
    print("5 -> 0.85")
    print("6 -> 0.30")
    print("7 -> 0.42")
    print("8 -> 0.51")
    print("9 -> 0.25")
    print("10 -> 0.57")
    print("11 -> 0.05")
    print()

    print("Estimated iterations for ε = 1e-4")
    print("Use")
    print("n >= log((ε(1-k))/|x1-x0|) / log(k)")
    print("for each problem.\n")



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