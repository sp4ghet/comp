h, w = map(int, input().split())

diffs = []
for y in range(h):
    row = map(int, input().split())
    diffs.append(list(row))

for y in range(h):
    row = map(int, input().split())
    for x, b in zip(range(w), row):
        diffs[y][x] = abs(diffs[y][x] - b)

m = 80 * (h + w)
dp = [[0 for j in range(w)] for k in range(h)]
d = m - diffs[0][0]
dp[0][0] = 1 << d

for y in range(h):
    for x in range(w):
        if x == y == 0:
            continue
        diff = diffs[y][x]
        if y != 0:
            dp[y][x] |= dp[y-1][x] << diff
            dp[y][x] |= dp[y-1][x] >> diff
        if x != 0:
            dp[y][x] |= dp[y][x-1] << diff
            dp[y][x] |= dp[y][x-1] >> diff

end = bin(dp[-1][-1])[2:][::-1]  # reverse

candidates = [abs(i-m) for i, b in enumerate(end) if b == '1']
ans = min(candidates)
print(ans)
