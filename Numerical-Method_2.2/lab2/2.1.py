def bisection(f, a, b, n):
    x = 0
    ans = []
    ans.append((a, b))
    for _ in range(n):
        x = (a+b)/2
        if f(x) == 0 or (b-a)/2 < 1e-9:
            return x
        else:
            if (f(a)*f(x) < 0):
                b = x
                ans.append((a, b))
            else:
                a = x
                ans.append((a, b))
        
    return ans
    
# ex-1:
f1 = lambda x: x**3 - x - 1

result1 = bisection(f1, 1, 2, 10)

print(f"{'n':<3} {'a':<10} {'b':<10} {'x_n':<12} {'f(x_n)':<12} {'new interval'}")

a, b = result1[0]

for i, (na, nb) in enumerate(result1[1:], start=1):
    x = (a + b) / 2

    print(
        f"{i:<3} "
        f"{a:<10.4f}"
        f"{b:<10.4f}"
        f"{x:<12.6f}"
        f"{f1(x):<12.6f}"
        f"[{na:.6f}, {nb:.6f}]"
    )

    a, b = na, nb


f2 = lambda x: x**3 - 2*x - 1