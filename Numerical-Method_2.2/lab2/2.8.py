import math



def ramanujan(a,mx=50,eps=1e-4):
    print(f"{'n':<5}{'bn':<15}{'convergent':<15}")
    b = [0]*(mx+1)
    b[1] = 1
    print(f"{1:<5}{b[1]:<15.6f}{'—':<15}")

    prev = None

    for k in range (2,mx+1,1):
        s = 0
        for j in range (1,k,1):
            if j <= len(a) and a[j-1] != 0:
                s += a[j-1]*b[k-j]
        b[k] = s
        if abs(b[k]) < 1e-15:

            break

        cn = b[k-1]/b[k]

        print(f"{k:<5}{b[k]:<15.6f}{cn:<15.6f}")
        if prev is not None and abs(cn-prev)<eps:
            print("\nAnswer =",round(cn,4))
            print("")
            return cn
        prev = cn
    print("\nAnswer =",round(prev,4))

    print("")

    return prev



def ex1():

    print("Exercise 1")

    print("x^3 - 9x^2 + 26x - 24 = 0 (roots 2,3,4)\n")

    a = [13/12,-3/8,1/24]

    ramanujan(a)



def ex2():

    print("Exercise 2")

    print("x*e^x = 1\n")

    a = [1/math.factorial(k-1) for k in range (1,51)]

    ramanujan(a)



def ex3():

    print("Exercise 3")

    print("3x - cos(x) - 1 = 0\n")

    a = [3/2,1/4,0,-1/48,0,1/1440]

    ramanujan(a)



def ex4():

    print("Exercise 4")

    print("1 - x + x^2/(2!)^2 - x^3/(3!)^2 + ... = 0\n")

    a = [(-1)**(k+1)/math.factorial(k)**2 for k in range (1,20,1)]

    ramanujan(a)



def ex5():

    print("Exercise 5")

    print("x^2 - 5x + 6 = 0 (roots 2,3)\n")

    a = [5/6,-1/6]

    ramanujan(a)



def ex6():

    print("Exercise 6")

    print("x^3 - 6x^2 + 11x - 6 = 0 (roots 1,2,3)\n")

    a = [11/6,-1,1/6]

    ramanujan(a)



def ex7():

    print("Exercise 7")

    print("2x^2 - 8x + 3 = 0\n")

    a = [8/3,-2/3]

    ramanujan(a)



def ex8():

    print("Exercise 8")

    print("x^3 - 4x^2 + 5x - 2 = 0  [(x-1)^2*(x-2)]\n")

    a = [5/2,-2,1/2]

    ramanujan(a)



def ex9():

    print("Exercise 9")

    print("x^3 - 2x^2 - 5x + 6 = 0 (roots 1,3,-2)\n")

    a = [-5/6,-1/3,1/6]

    ramanujan(a)



def ex10():

    print("Exercise 10")

    print("6x^3 - 11x^2 + 6x - 1 = 0 (roots 1, 1/2, 1/3)\n")

    a = [6,-11,6]

    ramanujan(a)



def ex11():

    print("Exercise 11")

    print("Verify ex7 answer against exact: (8 - sqrt(40)) / 4\n")

    exact = (8-math.sqrt(40))/4

    print(f"Exact smallest root = {exact:.6f} => {round(exact,4)}")

    print("Run ex7 again:")

    ex7()



def main():
    print("")
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