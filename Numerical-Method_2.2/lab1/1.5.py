import math
import sys
import numpy as np

# [ Why So Serious ]

print("="*70)
print("Exercise 1")
print("="*70)

# double
e = 1.0
while 1.0+e/2.0>1.0:
    e/=2.0

print("Double Machine Epsilon :",e)
print("2^-52 =",2**-52)
print()

# float(single)
e = np.float32(1.0)
one = np.float32(1.0)

while np.float32(one+e/2)>one:
    e = np.float32(e/2)

print("Float Machine Epsilon :",e)
print("2^-23 =",2**-23)


print("\n"+"="*70)
print("Exercise 2")
print("="*70)

eps = sys.float_info.epsilon

print("1 + eps      =",1.0+eps)
print("1 + eps/2    =",1.0+eps/2)


print("\n"+"="*70)
print("Exercise 3")
print("="*70)

x = 1e-4

d = (1-math.cos(x))/(x*x)
s = (2*(math.sin(x/2)**2))/(x*x)

print("Direct =",d)
print("Stable =",s)


print("\n"+"="*70)
print("Exercise 4")
print("="*70)

n = 10**6

a = 0.0
for i in range(1,n+1):
    a += 1/i

b = 0.0
for i in range(n,0,-1):
    b += 1/i

print("Increasing :",a)
print("Decreasing :",b)
print("Difference :",abs(a-b))


print("\n"+"="*70)
print("Exercise 5")
print("="*70)

a = 1
b = -1000
c = 1

x1 = (-b + math.sqrt(b*b-4*a*c))/(2*a)
x2 = (-b - math.sqrt(b*b-4*a*c))/(2*a)

y1 = (-b + math.sqrt(b*b-4*a*c))/(2*a)
y2 = c/(a*y1)

print("Naive roots")
print(x1)
print(x2)

print()
print("Stable roots")
print(y1)
print(y2)


print("\n"+"="*70)
print("Exercise 6")
print("="*70)

a = 1e16
b = -1e16
c = 1.0

print("(a+b)+c =", (a+b)+c)
print("a+(b+c) =", a+(b+c))


print("\n"+"="*70)
print("Exercise 7")
print("="*70)

eps = sys.float_info.epsilon

h = eps**(1/3)

print("Optimal h ≈",h)


print("\n"+"="*70)
print("Exercise 8")
print("="*70)

print("Largest Float :",sys.float_info.max)
print("Smallest Positive Float :",sys.float_info.min)


print("\n"+"="*70)
print("Exercise 9")
print("="*70)

x = -20

t = 1.0
sm = 1.0

for i in range(1,40):
    t *= x/i
    sm += t

ex = math.exp(x)
alt = 1/math.exp(20)

print("Maclaurin :",sm)
print("1/e^20    :",alt)
print("exp(-20)  :",ex)


print("\n"+"="*70)
print("Exercise 10")
print("="*70)

a = 1.234567891
b = 1.234567800

d = a-b

if d!=0:
    lost = -math.log10(abs(d))
else:
    lost = float("inf")

print("Difference =",d)
print("Approx lost significant digits =",lost)


print("\n"+"="*70)
print("Exercise 11")
print("="*70)

n = 100000

x = [1.0]*n
y = [1.0/3]*n

sm = 0.0
for i in range(n):
    sm += x[i]*y[i]

true = n/3

print("Dot Product =",sm)
print("True Value  =",true)
print("Error       =",abs(sm-true))


print("\n"+"="*70)
print("Exercise 12")
print("="*70)

def f(x):
    return math.exp(x)

tv = math.exp(1)

for k in range(1,13):
    h = 10**(-k)
    d = (f(1+h)-f(1-h))/(2*h)
    er = abs(d-tv)
    print("h =",h," Error =",er)