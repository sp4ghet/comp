n = int(input())
a = map(int, input().split())
bs = list(map(int, input().split()))
cs = list(map(int, input().split()))

ans = 0

prev = -1
for i in a:
    ans += bs[i-1]
    if i == prev+1:
        ans += cs[i-2]
    prev = i

print(ans)
