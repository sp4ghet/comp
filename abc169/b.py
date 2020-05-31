n = int(input())
a = map(int, input().split())
a = list(a)

for k in a:
    if k == 0:
        print(0)
        exit()

maxn = 10**18
ans = 1
for k in a:
    ans *= k
    if ans > maxn:
        ans = -1
        break


print(ans)
