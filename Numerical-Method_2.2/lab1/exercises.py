import math

# problem-1:
phi = lambda v: 9.8 - (12.5/68.1) * v
exact = lambda t: 53.39*(1-math.e**-((12.5/68.1)*t))

h = 1
t = 0
v = 0

while t<10:
    v = v + h*phi(v)
    t += h

euler = v
true = exact(10)

error = abs(true - euler)/true * 100
print(error)





# problem-2: [ wrong ]
exact = lambda yn: yn - h*yn

x = 0
euler = 0
while x <= 1:
    euler += math.e**-x
    x += 0.1

error = abs(exact(1)-euler)/exact(1) * 100
print(error)