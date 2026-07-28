import math

def f1(x):
    return -0.1*x**4 -0.15*x**3 -0.5*x**2 -0.25*x +1.2

def df1(x):
    return -0.4*x**3 -0.45*x**2 -x -0.25

def fd(f,x,h):
    return (f(x+h)-f(x))/h

def bd(f,x,h):
    return (f(x)-f(x-h))/h

def cd(f,x,h):
    return (f(x+h)-f(x-h))/(2*h)

def err(v,t):
    return abs((v-t)/t)*100


print("="*70)
print("Exercise 1")
print("="*70)

x = 0.5
h = 0.1
tv = df1(x)

ff = fd(f1,x,h)
bb = bd(f1,x,h)
cc = cd(f1,x,h)

print("True =",tv)
print("Forward :",ff," Error =",err(ff,tv),"%")
print("Backward:",bb," Error =",err(bb,tv),"%")
print("Centered:",cc," Error =",err(cc,tv),"%")


print("\n"+"="*70)
print("Exercise 2")
print("="*70)

f = math.exp
tv = math.exp(1)

for h in [0.1,0.05]:
    c = cd(f,1,h)
    print("h =",h)
    print("Centered =",c)
    print("Error =",err(c,tv),"%")
    print()


print("="*70)
print("Exercise 3")
print("="*70)

x = math.pi/4
tv = math.cos(x)
h = 0.1

c = cd(math.sin,x,h)

print("True =",tv)
print("Centered =",c)
print("Error =",err(c,tv),"%")


print("\n"+"="*70)
print("Exercise 4")
print("="*70)

x = 2
tv = 0.5
h = 0.1

c = cd(math.log,x,h)

print("True =",tv)
print("Centered =",c)
print("Error =",err(c,tv),"%")


print("\n"+"="*70)
print("Exercise 5")
print("="*70)

def f(x):
    return x**3

x = 2
h = 0.1

ans = (f(x+h)-2*f(x)+f(x-h))/(h*h)

print("Estimated second derivative =",ans)
print("True =",6*x)


print("\n"+"="*70)
print("Exercise 6")
print("="*70)

t = [0,1,2,3,4]
s = [0,0.7,1.8,3.4,5.5]

i = 2
h = 1

v = (s[i+1]-s[i-1])/(2*h)

print("Velocity at t=2 =",v)


print("\n"+"="*70)
print("Exercise 7")
print("="*70)

def f(x):
    return math.exp(x)

tv = 1

for h in [0.2,0.1,0.05,0.025]:
    ff = fd(f,0,h)
    print("h =",h," Forward =",ff," Error =",err(ff,tv),"%")


print("\n"+"="*70)
print("Exercise 8")
print("="*70)

def f(x):
    return x**3

x = 2
h = 0.1
tv = 3*x*x

ff = fd(f,x,h)
cc = cd(f,x,h)

print("True =",tv)
print("Forward =",ff," Error =",err(ff,tv),"%")
print("Centered =",cc," Error =",err(cc,tv),"%")


print("\n"+"="*70)
print("Exercise 9")
print("="*70)

def f(x):
    return math.exp(x)

x = 1

h = 0.1

d1 = cd(f,x,h)
d2 = cd(f,x,h/2)

rich = d2 + (d2-d1)/3

print("Centered(h)   =",d1)
print("Centered(h/2) =",d2)
print("Richardson    =",rich)
print("True          =",math.exp(1))


print("\n"+"="*70)
print("Exercise 10")
print("="*70)

x = 1
tv = math.exp(1)

for h in [1e-2,1e-4,1e-8,1e-12]:
    c = cd(math.exp,x,h)
    print("h =",h)
    print("Value =",c)
    print("Error =",err(c,tv),"%")
    print()


print("="*70)
print("Exercise 11")
print("="*70)

print("Centered Difference Formula:")
print("f'(x) ≈ (f(x+h)-f(x-h))/(2h)")
print("It is obtained by subtracting forward and backward Taylor expansions.")
print("Order of accuracy = O(h^2)")


print("\n"+"="*70)
print("Exercise 12")
print("="*70)

def f(x):
    return math.cos(x)*math.exp(-x)

x = 0.5
h = 0.05

c = cd(f,x,h)

print("Centered derivative =",c)
print("Exact derivative not required.")
print("Centered difference gives O(h^2) accuracy.")