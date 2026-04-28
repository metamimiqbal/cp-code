for _ in range(int(input())):
	n, k = map(int, input().split())
	a = sorted(list(map(int, input().split())))
	ans = 0
	pr = [0] * (n + 1)
	
	for i in range(n):
		pr[i + 1] = pr[i] + a[i]
	print(a)
	print(pr)
	for i in range(k + 1):
		print(i)
		ans = max(ans, pr[n - (k - i)] - pr[2 * i])
		print(pr[n - (k - i)], pr[2 * i])
	print(ans)