n, x, m = map(int, input().split())

a = x
ans = 0
al = []
for i in range(n):
    ans += a
    al.append(a)
    a = (a*a) % m

print(al)
print(sum(al))

# 13 2 19
# 2, 4, 16, 9, 5, 6, 17, 4, 16, 9, 5, 6, 17
