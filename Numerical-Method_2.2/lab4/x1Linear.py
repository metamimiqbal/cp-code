import math

x=[1, 2, 3, 4, 5]
y=[0.6, 2.4, 3.5, 4.8, 5.7]

sx = sy = sxx = sxy = 0

m = 4
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

cc = math.sqrt((st-s)/st)

print("x     y     x^2     xy     (y-y_bar)^2     (y-a0-a1x)^2")

for i in range(m):
    print(f"{x[i]:<5}{y[i]:<6}{x[i]*x[i]:<8}{x[i]*y[i]:<8}{(y[i]-y_bar)*(y[i]-y_bar):<17.4f}{(y[i]-a0-a1*x[i])*(y[i]-a0-a1*x[i]):.4f}")

print("∑x =",sx)
print("∑y =",sy)
print("∑x^2 =",sxx)
print("∑xy =",sxy)
print("x_bar =",x_bar)
print("y_bar =",y_bar)
print("a0 =",a0)
print("a1 =",a1)
print("Y =",a0,"+",a1,"x")
print("Correlation Coefficient =",cc)