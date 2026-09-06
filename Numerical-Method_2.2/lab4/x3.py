import math

x=[1, 3, 5, 7, 9]
y=[2.473, 6.722, 18.274, 49.673, 135.026]

sx = sy = sxx = sxy = 0

m = len(x)
for i in range(m):
    y[i] = math.log(y[i])
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

cc = math.sqrt((st-s)/st)

print("x     y     x^2     xy     (y-y_bar)^2     (y-a0-a1x)^2")

for i in range(m):
    print(f"{x[i]:<5.3f}{y[i]:<6.3f}{x[i]*x[i]:<8.3f}{x[i]*y[i]:<8.3f}{(y[i]-y_bar)*(y[i]-y_bar):<17.3f}{(y[i]-a0-a1*x[i])*(y[i]-a0-a1*x[i]):.3f}")

print("∑x =",sx)
print("∑y =",sy)
print("∑x^2 =",sxx)
print("∑xy =",sxy)
print("x_bar =",x_bar)
print("y_bar =",y_bar)
a = math.exp(a0)
print("a =",a)
print("b =",a1)
print("Y =",a,"e^(",a1,"x)")
print("Correlation Coefficient =",cc)