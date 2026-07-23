import math

# [ Why So Serious ]

def ex1():
    print("Exercise 1")
    print("e^0.5 using Maclaurin Series (3 Significant Figures)\n")

    x = 0.5
    true = math.exp(x)
    es = 0.05

    sm = 0.0
    fact = 1

    print(f"{'Terms':<8}{'Estimate':<15}{'Et(%)':<15}{'Ea(%)'}")

    old = 0

    for i in range(0,100):
        if(i!=0):
            fact*=i

        sm += (x**i)/fact

        et = abs((true-sm)/true)*100

        if(i==0):
            print(f"{i+1:<8}{sm:<15.6f}{et:<15.4f}---")
        else:
            ea = abs((sm-old)/sm)*100
            print(f"{i+1:<8}{sm:<15.6f}{et:<15.4f}{ea:.4f}")

            if(ea<es):
                print("\nAnswer =",round(sm,4))
                print("Terms Needed =",i+1)
                break

        old = sm

    print()


def ex2():
    print("Exercise 2")
    print("e^1 to 4 Significant Figures\n")

    x = 1
    true = math.exp(1)
    es = 0.005

    sm = 0
    fact = 1
    old = 0

    for i in range(0,100):
        if(i!=0):
            fact*=i

        sm += (x**i)/fact

        if(i!=0):
            ea = abs((sm-old)/sm)*100
            if(ea<es):
                print("Answer =",round(sm,5))
                print("Terms Needed =",i+1)
                break

        old = sm

    print()


def ex3():
    print("Exercise 3")
    print("sin(pi/6) using Maclaurin Series (3 Significant Figures)\n")

    x = math.pi/6
    true = math.sin(x)
    es = 0.05

    sm = 0
    old = 0

    for i in range(50):
        sm += ((-1)**i)*(x**(2*i+1))/math.factorial(2*i+1)

        if(i!=0):
            ea = abs((sm-old)/sm)*100
            if(ea<es):
                break

        old = sm

    print("Approx =",sm)
    print("True   =",true)
    print("Terms Needed =",i+1)
    print()


def ex4():
    print("Exercise 4")
    print("cos(0.3) using Maclaurin Series (4 Significant Figures)\n")

    x = 0.3
    true = math.cos(x)
    es = 0.005

    sm = 0
    old = 0

    for i in range(50):
        sm += ((-1)**i)*(x**(2*i))/math.factorial(2*i)

        if(i!=0):
            ea = abs((sm-old)/sm)*100
            if(ea<es):
                break

        old = sm

    print("Approx =",sm)
    print("True   =",true)
    print("Terms Needed =",i+1)
    print()


def ex5():
    print("Exercise 5")
    print("ln(1.2) using Maclaurin Series (3 Significant Figures)\n")

    x = 0.2
    true = math.log(1.2)
    es = 0.05

    sm = 0
    old = 0

    for i in range(1,100):
        sm += ((-1)**(i+1))*(x**i)/i

        if(i!=1):
            ea = abs((sm-old)/sm)*100
            if(ea<es):
                break

        old = sm

    print("Approx =",sm)
    print("True   =",true)
    print("Terms Needed =",i)
    print()


def ex6():
    print("Exercise 6")
    print()

    true = 2.718282
    ap = 2.716667

    Et = true-ap
    et = abs(Et/true)*100

    print("Et =",Et)
    print("et =",et,"%")
    print()


def ex7():
    print("Exercise 7")
    print("Stopping Criterion\n")

    for n in range(1,6):
        es = 0.5*(10**(2-n))
        print(f"{n} Significant Figure(s) -> es = {es}%")

    print()


def ex8():
    print("Exercise 8")
    print("Square Root of 2 using Newton-Raphson (4 Significant Figures)\n")

    true = math.sqrt(2)
    es = 0.005

    x = 1
    old = x

    print(f"{'Iter':<8}{'Estimate':<15}{'Ea(%)'}")

    for i in range(1,100):
        x = 0.5*(old+2/old)

        ea = abs((x-old)/x)*100

        print(f"{i:<8}{x:<15.8f}{ea:.6f}")

        if(ea<es):
            break

        old = x

    print("Approx =",x)
    print("True   =",true)
    print()


def ex9():
    print("Exercise 9")
    print("e^0.5 Errors Table\n")

    x = 0.5
    true = math.exp(x)

    sm = 0
    old = 0

    print(f"{'Term':<8}{'Estimate':<15}{'Et(%)':<15}{'Ea(%)'}")

    fact = 1

    for i in range(0,6):
        if(i!=0):
            fact*=i

        sm += (x**i)/fact

        et = abs((true-sm)/true)*100

        if(i==0):
            print(f"{i+1:<8}{sm:<15.6f}{et:<15.6f}---")
        else:
            ea = abs((sm-old)/sm)*100
            print(f"{i+1:<8}{sm:<15.6f}{et:<15.6f}{ea:.6f}")

        old = sm

    print()


def ex10():
    print("Exercise 10")
    print("Leibniz Series for pi (2 Significant Figures)\n")

    true = math.pi
    es = 0.5

    sm = 0
    old = 0

    for i in range(500000):
        sm += ((-1)**i)/(2*i+1)
        pi = 4*sm

        if(i!=0):
            ea = abs((pi-old)/pi)*100

            if(ea<es):
                break

        old = pi

    print("Approx =",pi)
    print("True   =",true)
    print("Terms Needed =",i+1)
    print("Comment : Leibniz series converges very slowly.")
    print()


def ex11():
    print("Exercise 11")
    print()

    x = 24.5
    tol = 0.05

    rel = tol/x
    per = rel*100

    sig = math.floor(2-math.log10(per/0.5))

    print("Relative Error =",rel)
    print("Relative Error (%) =",per)
    print("Approx Significant Figures =",sig)
    print()


def ex12():
    print("Exercise 12")
    print("Stopping Algorithm with Maximum Iteration\n")

    x = 0.5
    es = 0.05
    nmax = 4

    true = math.exp(x)

    sm = 0
    fact = 1
    old = 0

    ok = False

    for i in range(nmax):
        if(i!=0):
            fact*=i

        sm += (x**i)/fact

        if(i!=0):
            ea = abs((sm-old)/sm)*100

            if(ea<es):
                ok = True
                break

        old = sm

    print("Estimate =",sm)

    if(ok):
        print("Convergence Achieved.")
    else:
        print("Warning : Convergence NOT achieved within",nmax,"terms.")

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