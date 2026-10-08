import math


x = [1, 2, 3, 4, 5]
y = [2.1, 4.2, 5.8, 8.1, 10.2]

sx = sy = sxx = sxy = 0

m = 5
for i in range(m):
    sx += x[i]
    sy += y[i]
    sxx += (x[i]*x[i])
    sxy += (x[i]*y[i])

d = m*sxx - (sx*sx)
a1 = ((m*sxy) - (sx*sy))/d

x_bar = sx/m
y_bar = sy/m

a0 = y_bar - a1*x_bar

st = s = 0
for i in range(m):
    st += (y[i]-y_bar)*(y[i]-y_bar)
    s += (y[i]-a0-a1*x[i])*(y[i]-a0-a1*x[i])


def ff(x):
    return a0 + a1*x



print(f"a0 = {a0:0.4f}")
print(f"a1 = {a1:0.4f}")
print(f"y = {a0: 0.4f} + {a1: 0.4f}x")

print(f"The functional value for x = 6 is:{ff(6): 0.4f}")


