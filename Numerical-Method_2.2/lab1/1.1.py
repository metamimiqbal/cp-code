import math

def euler(f,t0,y0,h,tend):
    t = t0
    y = y0
    ans = []

    while t<=tend+1e-9:
        ans.append((round(t,10),y))
        y = y + f(t,y)*h
        t = t + h

    return ans


def tb(v):
    for x,y in v:
        print(f"{x:8.3f} {y:14.6f}")
    print("")


#1
print("="*60)
print("Exercise 1")
g = 9.8
c = 12.5
m = 68.1

for h in [1,0.5,0.25]:
    print("h =",h)

    def f(t,v):
        return g-(c/m)*v

    a = euler(f,0,0,h,10)
    print("t         Euler_v")
    tb(a)

    ex = (g*m/c)*(1-math.exp(-(c/m)*10))
    er = abs(a[-1][1]-ex)
    print("Exact at t=10 =",round(ex,6))
    print("Error =",round(er,6))
    print("")


#2
print("="*60)
print("Exercise 2")

def f(t,y):
    return -y

a = euler(f,0,1,0.1,1)
print("t         Euler_y")
tb(a)

print("Exact x=1 =",math.exp(-1))
print("")


#3
print("="*60)
print("Exercise 3")

def f(t,y):
    return t+y

a = euler(f,0,1,0.1,1)
print("t         Euler_y")
tb(a)

print("Exact x=1 =",2*math.exp(1)-2)
print("")


#4
print("="*60)
print("Exercise 4")

def f(t,y):
    return y-t*t+1

a = euler(f,0,0.5,0.2,1)
print("t         Euler_y")
tb(a)

ex = (1+1)**2-0.5*math.exp(1)
print("Exact x=1 =",ex)
print("")


#5
print("="*60)
print("Exercise 5")

def f(t,y):
    return -2*t*y

a = euler(f,0,1,0.1,1)
print("t         Euler_y")
tb(a)

print("Exact x=1 =",math.exp(-1))
print("")


#6
print("="*60)
print("Exercise 6")

def f(t,v):
    return 9.8-0.25*v*v

a = euler(f,0,0,0.5,20)
print("t         Euler_v")
tb(a)

print("Estimated terminal velocity =",a[-1][1])
print("Exact terminal velocity =",math.sqrt(9.8/0.25))
print("")


#7
print("="*60)
print("Exercise 7")

def f(t,T):
    return -0.07*(T-20)

a = euler(f,0,90,2,20)
print("t         Euler_T")
tb(a)

ex = 20+70*math.exp(-0.07*20)
print("Exact T(20) =",ex)
print("")


#8
print("="*60)
print("Exercise 8")

R = 1
C = 1
V = 5

def f(t,q):
    return (V-q/C)/R

a = euler(f,0,0,0.1,1)
print("t         Euler_q")
tb(a)


#9
print("="*60)
print("Exercise 9")

def f(t,p):
    return 0.8*p*(1-p/10)

a = euler(f,0,1,0.25,5)
print("t         Euler_p")
tb(a)


#10
print("="*60)
print("Exercise 10")

def f(t,v):
    return 9.8

a = euler(f,0,0,1,10)
print("t         Euler_v")
tb(a)

print("Exact solution : v = 9.8 t")
print("")


#11
print("="*60)
print("Exercise 11")

hs = [0.2,0.1,0.05,0.025]

for h in hs:

    def f(t,y):
        return -y

    a = euler(f,0,1,h,1)
    er = abs(a[-1][1]-math.exp(-1))
    print("h =",h," Error =",er)

print("")


#12
print("="*60)
print("Exercise 12")
print("Already implemented.")
print("The generic euler(f,t0,y0,h,tend) driver solves Exercises 2-9 by only changing f().")