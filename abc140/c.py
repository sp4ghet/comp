n = int(input())
bs = list(map(int, input().split()))

ans = bs[0]
for i in range(0, n-2):
    ans += min(bs[i], bs[i+1])

ans += bs[-1]

print(ans)
