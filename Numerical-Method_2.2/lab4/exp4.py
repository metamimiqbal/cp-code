import math


def solve(a,b):

    n = len(b)

    for i in range(n):

        mx = i

        for j in range(i+1,n):
            if abs(a[j][i])>abs(a[mx][i]):
                mx = j

        a[i],a[mx] = a[mx],a[i]
        b[i],b[mx] = b[mx],b[i]

        for j in range(i+1,n):

            r = a[j][i]/a[i][i]

            for k in range(i,n):
                a[j][k] -= r*a[i][k]

            b[j] -= r*b[i]

    x = [0]*n

    for i in range(n-1,-1,-1):

        sm = 0

        for j in range(i+1,n):
            sm += a[i][j]*x[j]

        x[i] = (b[i]-sm)/a[i][i]

    return x


def fit_quad(x,y):

    m = len(x)

    sx = 0
    sy = 0
    sx2 = 0
    sx3 = 0
    sx4 = 0
    sxy = 0
    sx2y = 0

    print(f"{'x':<8}{'y':<8}{'x^2':<10}{'x^3':<10}{'x^4':<10}{'xy':<10}{'x^2y'}")

    for i in range(m):

        x2 = x[i]**2
        x3 = x[i]**3
        x4 = x[i]**4
        xy = x[i]*y[i]
        x2y = x[i]**2*y[i]

        sx += x[i]
        sy += y[i]
        sx2 += x2
        sx3 += x3
        sx4 += x4
        sxy += xy
        sx2y += x2y

        print(f"{x[i]:<8.2f}{y[i]:<8.2f}{x2:<10.2f}{x3:<10.2f}{x4:<10.2f}{xy:<10.2f}{x2y:.2f}")

    print("-"*68)
    print(f"{sx:<8.2f}{sy:<8.2f}{sx2:<10.2f}{sx3:<10.2f}{sx4:<10.2f}{sxy:<10.2f}{sx2y:.2f}")
    print()

    a = [
        [m,sx,sx2],
        [sx,sx2,sx3],
        [sx2,sx3,sx4]
    ]

    b = [sy,sxy,sx2y]

    c = solve(a,b)

    a0 = c[0]
    a1 = c[1]
    a2 = c[2]

    print("a0 =",a0)
    print("a1 =",a1)
    print("a2 =",a2)
    print()
    print("Y =",a0,"+",a1,"x +",a2,"x^2")
    print()


def fit_cubic(x,y):

    m = len(x)

    sx = 0
    sy = 0
    sx2 = 0
    sx3 = 0
    sx4 = 0
    sx5 = 0
    sx6 = 0
    sxy = 0
    sx2y = 0
    sx3y = 0

    print(f"{'x':<8}{'y':<8}{'x^2':<10}{'x^3':<10}{'x^4':<10}{'x^5':<10}{'x^6':<10}{'xy':<10}{'x^2y':<10}{'x^3y'}")

    for i in range(m):

        x2 = x[i]**2
        x3 = x[i]**3
        x4 = x[i]**4
        x5 = x[i]**5
        x6 = x[i]**6

        xy = x[i]*y[i]
        x2y = x[i]**2*y[i]
        x3y = x[i]**3*y[i]

        sx += x[i]
        sy += y[i]
        sx2 += x2
        sx3 += x3
        sx4 += x4
        sx5 += x5
        sx6 += x6
        sxy += xy
        sx2y += x2y
        sx3y += x3y

        print(f"{x[i]:<8.2f}{y[i]:<8.2f}{x2:<10.2f}{x3:<10.2f}{x4:<10.2f}{x5:<10.2f}{x6:<10.2f}{xy:<10.2f}{x2y:<10.2f}{x3y:.2f}")

    print("-"*110)
    print(f"{sx:<8.2f}{sy:<8.2f}{sx2:<10.2f}{sx3:<10.2f}{sx4:<10.2f}{sx5:<10.2f}{sx6:<10.2f}{sxy:<10.2f}{sx2y:<10.2f}{sx3y:.2f}")
    print()

    a = [
        [m,sx,sx2,sx3],
        [sx,sx2,sx3,sx4],
        [sx2,sx3,sx4,sx5],
        [sx3,sx4,sx5,sx6]
    ]

    b = [sy,sxy,sx2y,sx3y]

    c = solve(a,b)

    a0 = c[0]
    a1 = c[1]
    a2 = c[2]
    a3 = c[3]

    print("a0 =",a0)
    print("a1 =",a1)
    print("a2 =",a2)
    print("a3 =",a3)
    print()
    print("Y =",a0,"+",a1,"x +",a2,"x^2 +",a3,"x^3")
    print()


def ex1():
    print("Exercise 4.1")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [0,1,2]
    y = [1,6,17]

    fit_quad(x,y)


def ex2():
    print("Exercise 4.2")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [1,3,4,6]
    y = [0.63,2.05,4.08,10.78]

    fit_quad(x,y)


def ex3():
    print("Exercise 4.3")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [0,1,2,3,4]
    y = [1,1.8,1.3,2.5,6.3]

    fit_quad(x,y)


def ex4():
    print("Exercise 4.4")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [1,2,3,4,5,6]
    y = [2,5,10,17,26,37]

    fit_quad(x,y)


def ex5():
    print("Exercise 4.5")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [-2,-1,0,1,2]
    y = [4.1,1.0,0.1,1.1,3.9]

    fit_quad(x,y)


def ex6():
    print("Exercise 4.6")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [0,2,4,6,8,10]
    y = [5.0,6.2,9.0,12.5,18.0,24.5]

    fit_quad(x,y)


def ex7():
    print("Exercise 4.7")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [1,2,3,4,5,6,7]
    y = [2.3,5.2,9.7,16.5,24.5,34.0,46.0]

    fit_quad(x,y)


def ex8():
    print("Exercise 4.8")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [1,1.5,2,2.5,3,3.5,4]
    y = [1.1,1.3,1.6,2.0,2.7,3.4,4.1]

    fit_quad(x,y)


def ex9():
    print("Exercise 4.9")
    print("Fit Y = a0 + a1x + a2x^2\n")

    x = [10,15,20,25,30]
    y = [35.3,32.4,29.2,28.1,31.0]

    fit_quad(x,y)


def ex10():
    print("Exercise 4.10")
    print("Projectile Motion\n")

    t = [0,1,2,3,4]
    h = [2,27,42,47,42]

    fit_quad(t,h)

    print("Expected equation:")
    print("h = 2 + 30t - 5t^2")
    print()

    tm = -30/(2*(-5))

    hm = 2+30*tm-5*tm**2

    print("Time of maximum height =",tm)
    print("Maximum height =",hm)
    print()


def ex11():
    print("Exercise 4.11")
    print("Cubic Fit: Y = a0 + a1x + a2x^2 + a3x^3\n")

    x = [0,1,2,3,4,5]
    y = [1,0,1,10,33,76]

    fit_cubic(x,y)


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