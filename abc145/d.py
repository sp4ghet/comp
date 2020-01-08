from math import factorial
pos = map(int, input().split())
p = 10**9 + 7
x, y = sorted(pos)

if (x+y) % 3 != 0:
    print(0)
    exit()

n = (-x + 2 * y) // 3
m = (-y + 2 * x) // 3


def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p  # n!/k!
        den = (den * (i + 1)) % p  # (n-k)!
    return (num * pow(den,
                      p - 2, p)) % p


ans = ncr(n+m, n, p)
print(ans)
