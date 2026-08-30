import math

def sysnewton(f,g,fx,fy,gx,gy,x0,y0,eps = 1e-4,mx = 100):

    print(f"{'n':<5}{'xn':<15}{'yn':<15}")

    print(f"{0:<5}{x0:<15.6f}{y0:<15.6f}")

    for i in range (1,mx+1,1):

        f0 = f(x0,y0)

        g0 = g(x0,y0)

        fxv = fx(x0,y0); fyv = fy(x0,y0)

        gxv = gx(x0,y0); gyv = gy(x0,y0)

        D = fxv*gyv-gxv*fyv

        if(abs(D)<1e-15):

            print("D=0, stopping")

            return

        h = (-f0*gyv+g0*fyv)/D

        k = (-g0*fxv+f0*gxv)/D

        x0 += h; y0 += k

        print(f"{i:<5}{x0:<15.6f}{y0:<15.6f}")

        if(abs(h)<eps and abs(k)<eps):

            print(f"\nAnswer = ({round(x0,4)}, {round(y0,4)})")

            print("")

            return

    print(f"\nAnswer = ({round(x0,4)}, {round(y0,4)})")

    print("")



def ex1_10():

    print("Exercise 1")

    print("3yx^2-10x+7=0, y^2-5y+4=0; (0.5,0.5)\n")

    def f(x,y): return 3*y*x**2-10*x+7

    def g(x,y): return y**2-5*y+4

    def fx(x,y): return 6*y*x-10

    def fy(x,y): return 3*x**2

    def gx(x,y): return 0

    def gy(x,y): return 2*y-5

    sysnewton(f,g,fx,fy,gx,gy,0.5,0.5)



def ex2_10():

    print("Exercise 2")

    print("x^2+y^2-1=0, y-x^2=0; (0.8,0.6)\n")

    def f(x,y): return x**2+y**2-1

    def g(x,y): return y-x**2

    def fx(x,y): return 2*x

    def fy(x,y): return 2*y

    def gx(x,y): return -2*x

    def gy(x,y): return 1

    sysnewton(f,g,fx,fy,gx,gy,0.8,0.6)



def ex3_10():

    print("Exercise 3")

    print("sin(x)-y+0.9793=0, cos(y)-x+0.6703=0; (0.5,1.5)\n")

    def f(x,y): return math.sin(x)-y+0.9793

    def g(x,y): return math.cos(y)-x+0.6703

    def fx(x,y): return math.cos(x)

    def fy(x,y): return -1

    def gx(x,y): return -1

    def gy(x,y): return -math.sin(y)

    sysnewton(f,g,fx,fy,gx,gy,0.5,1.5)



def ex4_10():

    print("Exercise 4")

    print("x^2+xy+y^2-7=0, x^3+y^3-9=0; (1.5,0.5)\n")

    def f(x,y): return x**2+x*y+y**2-7

    def g(x,y): return x**3+y**3-9

    def fx(x,y): return 2*x+y

    def fy(x,y): return x+2*y

    def gx(x,y): return 3*x**2

    def gy(x,y): return 3*y**2

    sysnewton(f,g,fx,fy,gx,gy,1.5,0.5)



def ex5_10():

    print("Exercise 5")

    print("x^2-2x-y+0.5=0, x^2+4y^2-4=0; (2,0.25)\n")

    def f(x,y): return x**2-2*x-y+0.5

    def g(x,y): return x**2+4*y**2-4

    def fx(x,y): return 2*x-2

    def fy(x,y): return -1

    def gx(x,y): return 2*x

    def gy(x,y): return 8*y

    sysnewton(f,g,fx,fy,gx,gy,2,0.25)



def ex6_10():

    print("Exercise 6")

    print("x^2+y^2-4=0, xy-1=0; (1.9,0.6)\n")

    def f(x,y): return x**2+y**2-4

    def g(x,y): return x*y-1

    def fx(x,y): return 2*x

    def fy(x,y): return 2*y

    def gx(x,y): return y

    def gy(x,y): return x

    sysnewton(f,g,fx,fy,gx,gy,1.9,0.6)



def ex7_10():

    print("Exercise 7")

    print("e^x-y=0, xy-e^x=0; (0.8,1.5)\n")

    def f(x,y): return math.exp(x)-y

    def g(x,y): return x*y-math.exp(x)

    def fx(x,y): return math.exp(x)

    def fy(x,y): return -1

    def gx(x,y): return y-math.exp(x)

    def gy(x,y): return x

    sysnewton(f,g,fx,fy,gx,gy,0.8,1.5)



def ex8_10():

    print("Exercise 8")

    print("x^2+y-11=0, x+y^2-7=0; (3.5,1.8)\n")

    def f(x,y): return x**2+y-11

    def g(x,y): return x+y**2-7

    def fx(x,y): return 2*x

    def fy(x,y): return 1

    def gx(x,y): return 1

    def gy(x,y): return 2*y

    sysnewton(f,g,fx,fy,gx,gy,3.5,1.8)



def ex9_10():

    print("Exercise 9")

    print("x^2-y-1=0, x-y^2+1=0; (1.5,1.5)\n")

    def f(x,y): return x**2-y-1

    def g(x,y): return x-y**2+1

    def fx(x,y): return 2*x

    def fy(x,y): return -1

    def gx(x,y): return 1

    def gy(x,y): return -2*y

    sysnewton(f,g,fx,fy,gx,gy,1.5,1.5)



def ex10_10():

    print("Exercise 10")

    print("2-link robot arm: cos(t1)+cos(t1+t2)=1.2, sin(t1)+sin(t1+t2)=0.8; (0,1.5)\n")

    def f(x,y): return math.cos(x)+math.cos(x+y)-1.2

    def g(x,y): return math.sin(x)+math.sin(x+y)-0.8

    def fx(x,y): return -math.sin(x)-math.sin(x+y)

    def fy(x,y): return -math.sin(x+y)

    def gx(x,y): return math.cos(x)+math.cos(x+y)

    def gy(x,y): return math.cos(x+y)

    sysnewton(f,g,fx,fy,gx,gy,0,1.5)



def ex11_10():

    print("Exercise 11")

    print("For problem 4, verify (2,1) is exact and discuss convergence\n")

    x,y = 2,1

    f = x**2+x*y+y**2-7

    g = x**3+y**3-9

    print(f"f(2,1) = {f}, g(2,1) = {g}")

    print("Both zero => (2,1) is exact root")

    print("Starting from (1.5,0.5) the iteration converges to this root.")

    print("")



def main():
    print("="*60)
    print("EXPERIMENT 2.10 : NEWTON-RAPHSON FOR SYSTEMS")
    print("="*60)
    print("")
    ex1_10(); 
    ex2_10(); 
    ex3_10(); 
    ex4_10(); 
    ex5_10()
    ex6_10(); 
    ex7_10(); 
    ex8_10(); 
    ex9_10(); 
    ex10_10(); 
    ex11_10()



main()