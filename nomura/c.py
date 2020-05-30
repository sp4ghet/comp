n = int(input())+1
a = list(map(int, input().split()))

b = [0]*n
c = [0]*n

now = 1
for i in range(n):
    b[i] = now
    now -= a[i]
    if now < 0:
        print(-1)
        exit()

    if now == 0 and i != n-1:
        print(-1)
        exit()
    now *= 2

a = list(reversed(a))
c[0] = a[0]
now = a[0]
for i in range(1, n):
    now += a[i]
    c[i] = now

c = list(reversed(c))

ans = 0
for i in range(n):
    ans += min(b[i], c[i])

print(ans)
