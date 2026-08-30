import math


def ex1():
    print("Exercise 1")
    print("Straight Line Y = a0 + a1x\n")

    x = [1,2,3,4,5]
    y = [0.6,2.4,3.5,4.8,5.7]

    m = len(x)

    sx = 0
    sy = 0
    sx2 = 0
    sxy = 0

    for i in range(m):
        sx += x[i]
        sy += y[i]
        sx2 += x[i]**2
        sxy += x[i]*y[i]

    xb = sx/m
    yb = sy/m

    D = m*sx2-sx*sx

    a1 = (m*sxy-sx*sy)/D
    a0 = yb-a1*xb

    st = 0
    sr = 0

    print(f"{'x':<8}{'y':<8}{'x^2':<8}{'xy':<8}{'(y-ȳ)^2':<15}{'(y-y-a0-a1x)^2'}")

    for i in range(m):
        stt = (y[i]-yb)**2
        srr = (y[i]-a0-a1*x[i])**2

        st += stt
        sr += srr

        print(f"{x[i]:<8}{y[i]:<8.1f}{x[i]**2:<8}{x[i]*y[i]:<8.1f}{stt:<15.4f}{srr:.4f}")

    print()
    print("Σx =",sx)
    print("Σy =",sy)
    print("Σx^2 =",sx2)
    print("Σxy =",sxy)
    print()

    print("x̄ =",xb)
    print("ȳ =",yb)
    print()

    print("D =",D)
    print("a1 =",a1)
    print("a0 =",a0)
    print()

    print("Y =",a0,"+",a1,"x")

    cc = math.sqrt((st-sr)/st)

    print("Correlation Coefficient =",cc)
    print()


def main():

    ex1()


main()