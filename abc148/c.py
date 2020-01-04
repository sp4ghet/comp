a,b = map(int, input().split())

def gcd(n,m):
    while m:
        n, m = m, n % m
    return n

def lcm(n,m):

    return (n*m) // gcd(n,m)

print(lcm(a,b))
