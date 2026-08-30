import math
x=[0, 1, 2]
y=[1, 6, 17]
sx = sy = sxx = sxxx = sxxxx = sxy = sxxy = 0
m = 3

for i in range(m):
    sx += x[i]
    sy += y[i]
    sxx += (x[i]*x[i])
    sxxx += (x[i]*x[i]*x[i])
    sxxxx += (x[i]*x[i]*x[i]*x[i])
    sxy += (x[i]*y[i])
    sxxy += (x[i]*x[i]*y[i])

print("x     y     x^2     x^3     x^4     xy     x^2y")

for i in range(m):
    print(f"{x[i]:<6}{y[i]:<6}{x[i]*x[i]:<8}{x[i]**3:<8}{x[i]**4:<8}{x[i]*y[i]:<8}{x[i]*x[i]*y[i]:.3f}")

print("∑x =",sx)
print("∑y =",sy)
print("∑x^2 =",sxx)
print("∑x^3 =",sxxx)
print("∑x^4 =",sxxxx)
print("∑xy =",sxy)
print("∑x^2y =",sxxy)


def det(a,b,c,d,e,f,g,h,i):
    return a*(e*i-f*h)-b*(d*i-f*g)+c*(d*h-e*g)

D = det(m,sx,sxx,sx,sxx,sxxx,sxx,sxxx,sxxxx)
D0 = det(sy,sx,sxx,sxy,sxx,sxxx,sxxy,sxxx,sxxxx)
D1 = det(m,sy,sxx,sx,sxy,sxxx,sxx,sxxy,sxxxx)
D2 = det(m,sx,sy,sx,sxx,sxy,sxx,sxxx,sxxy)
a0 = D0/D
a1 = D1/D
a2 = D2/D
print()
print("a0 =",a0)
print("a1 =",a1)
print("a2 =",a2)
print()
print("Y =",a0,"+",a1,"x +",a2,"x^2")