import math


def ex3():
    print("Exercise 3")
    print("Exponential Law: y = ae^bx\n")

    x = [0,1,2,3,4]
    y = [1.0,1.85,2.72,4.48,7.39]

    m = len(x)

    X = []
    Y = []

    for i in range(m):
        X.append(x[i])
        Y.append(math.log(y[i]))

    sx = 0
    sy = 0
    sx2 = 0
    sxy = 0

    print(f"{'X':<8}{'Y':<12}{'X^2':<8}{'XY'}")

    for i in range(m):
        sx += X[i]
        sy += Y[i]
        sx2 += X[i]**2
        sxy += X[i]*Y[i]

        print(f"{X[i]:<8.0f}{Y[i]:<12.4f}{X[i]**2:<8.0f}{X[i]*Y[i]:.4f}")

    print()
    print("ΣX =",sx)
    print("ΣY =",sy)
    print("ΣX^2 =",sx2)
    print("ΣXY =",sxy)
    print()

    xb = sx/m
    yb = sy/m

    D = m*sx2-sx*sx

    A1 = (m*sxy-sx*sy)/D
    A0 = yb-A1*xb

    a = math.exp(A0)
    b = A1

    print("A0 =",A0)
    print("A1 =",A1)
    print()

    print("a =",a)
    print("b =",b)
    print()

    print("Hence,")
    print("y =",a,"e^(",b,"x )")
    print()


def main():

    ex3()


main()