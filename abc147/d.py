n = int(input())

a = list(map(int, input().split()))

mod = 10**9 + 7
ans = 0
for i in range(60):
    bit = 1 << i
    oc = 0
    zc = 0
    for x in a:
        if x & bit != 0:
            oc += 1
        else:
            zc += 1

    add = zc * oc * bit
    ans = (ans + add % mod) % mod
    print(bit)

print(ans)
