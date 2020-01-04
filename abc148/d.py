n = int(input())
bricks = map(int, input().split())

ans = 0
cur = 1
for brick in bricks:
    if brick != cur:
        ans += 1
    else:
        cur += 1

if cur == 1:
    ans = -1

print(ans)