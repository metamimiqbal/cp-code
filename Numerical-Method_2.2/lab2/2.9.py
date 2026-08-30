import math


def sysiter(F,G,x0,y0,eps = 1e-4,mx = 100):

    print(f"{'n':<5}{'xn':<15}{'yn':<15}")

    print(f"{0:<5}{x0:<15.6f}{y0:<15.6f}")

    for i in range (1,mx+1,1):

        x1 = F(x0,y0)

        y1 = G(x0,y0)

        print(f"{i:<5}{x1:<15.6f}{y1:<15.6f}")

        if(abs(x1-x0)<eps and abs(y1-y0)<eps):

            print(f"\nAnswer = ({round(x1,4)}, {round(y1,4)})")

            print("")

            return

        x0,y0 = x1,y1

    print(f"\nAnswer = ({round(x0,4)}, {round(y0,4)})")

    print("")


def ex1_9():

    print("Exercise 1")

    print("y^2-5y+4=0, 3yx^2-10x+7=0; (0.5,0.5)\n")

    def F(x,y): return (3*y*x**2+7)/10

    def G(x,y): return (y**2+4)/5

    sysiter(F,G,0.5,0.5)


def ex2_9():

    print("Exercise 2")

    print("x^2+y^2-4=0, xy-1=0; (1.9,0.5)\n")

    def F(x,y): return math.sqrt(4-y**2) if 4-y**2>=0 else x

    def G(x,y): return 1/x if x!=0 else y

    sysiter(F,G,1.9,0.5)


def ex3_9():

    print("Exercise 3")

    print("x^2-2x-y+0.5=0, x^2+4y^2-4=0; (0,1)\n")

    # x = (x^2 - y + 0.5)/2, y = sqrt((4-x^2)/4)

    def F(x,y): return (x**2-y+0.5)/2

    def G(x,y): return math.sqrt(max(0,(4-x**2)/4))

    sysiter(F,G,0,1)


def ex4_9():

    print("Exercise 4")

    print("x^2+y^2-1=0, y-x^2=0; (0.8,0.6)\n")

    def F(x,y): return math.sqrt(1-y**2) if 1-y**2>=0 else x

    def G(x,y): return x**2

    sysiter(F,G,0.8,0.6)


def ex5_9():

    print("Exercise 5")

    print("x=1/10*(x^2+y^2+8), y=1/10*(xy^2+x+8); (0,0)\n")

    def F(x,y): return (x**2+y**2+8)/10

    def G(x,y): return (x*y**2+x+8)/10

    sysiter(F,G,0,0)


def ex6_9():

    print("Exercise 6")

    print("sin(x)+y^2-1=0, x+cos(y)-1.2=0; (0.5,0.5)\n")

    def F(x,y): return math.asin(1-y**2) if abs(1-y**2)<=1 else x

    def G(x,y): return math.acos(1.2-x) if abs(1.2-x)<=1 else y

    sysiter(F,G,0.5,0.5)


def ex7_9():

    print("Exercise 7")

    print("x=0.5+0.2*sin(x+y), y=1+0.1*cos(x-y); (0.5,1)\n")

    def F(x,y): return 0.5+0.2*math.sin(x+y)

    def G(x,y): return 1+0.1*math.cos(x-y)

    sysiter(F,G,0.5,1)


def ex8_9():

    print("Exercise 8")

    print("2x^2-xy-5x+1=0, x+3*log10(x)-y^2=0; (3.5,2.2)\n")

    def F(x,y): return ((y+5)+math.sqrt((y+5)**2-8))/4 if (y+5)**2>=8 else x

    def G(x,y): return math.sqrt(x+3*math.log10(x)) if x>0 and x+3*math.log10(x)>=0 else y

    sysiter(F,G,3.5,2.2)


def ex9_9():

    print("Exercise 9")

    print("x^2+y-11=0, x+y^2-7=0; (3.5,1.8)\n")

    def F(x,y): return math.sqrt(11-y) if 11-y>=0 else x

    def G(x,y): return math.sqrt(7-x) if 7-x>=0 else y

    sysiter(F,G,3.5,1.8)


def ex10_9():

    print("Exercise 10")

    print("x^2-y-1=0, x-y^2+1=0; (1.5,1.5)\n")

    def F(x,y): return math.sqrt(y+1) if y+1>=0 else x

    def G(x,y): return math.sqrt(x+1) if x+1>=0 else y

    sysiter(F,G,1.5,1.5)


def ex11_9():

    print("Exercise 11")

    print("Partial derivative check at start points\n")

    print("Ex1: F=1/10*(3yx^2+7), G=1/5*(y^2+4)")

    print("  |Fx|+|Fy| = |6xy/10| + |3x^2/10| at (0.5,0.5):")

    x,y = 0.5,0.5

    print(f"  = {abs(6*x*y/10)+abs(3*x**2/10):.4f} < 1 =>",abs(6*x*y/10)+abs(3*x**2/10)<1)

    print(f"  |Gx|+|Gy| = 0 + |2y/5| = {abs(2*y/5):.4f} < 1 =>",abs(2*y/5)<1)

    print("")


def main():

    print("="*60)

    print("EXPERIMENT 2.9 : ITERATION FOR SYSTEMS")

    print("="*60)

    print("")

    ex1_9()

    ex2_9()

    ex3_9()

    ex4_9()

    ex5_9()

    ex6_9()

    ex7_9()

    ex8_9()

    ex9_9()

    ex10_9()

    ex11_9()


main()