n = int(input())
a = map(int, input().split())
a = list(sorted(a))
big = a[n-1]
mark = [0]*(big+1)
for x in a:
    mark[x] += 1
    if mark[x] > 1:
        continue
    for j in range(x*2, big+1, x):
        mark[j] += 1

ans = 0
for x in a:
    if mark[x] == 1:
        ans += 1

print(ans)
