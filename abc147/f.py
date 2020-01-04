import numpy as np
n, x, d = map(int, input().split())
if d < 0:
    d = -d
    x = -x

if d == 0:
    if x == 0:
        print(1)
    else:
        print(n+1)
    exit()

mods = np.ndarray((d, 1, 2), dtype=int)

for k in range(n+1):
    l_k = k*(k-1) // 2
    r_k = l_k + k*(n-k)
    c_k = k*x + l_k*d
    size = r_k - l_k
    np.append(mods[int(c_k % d)], (c_k, size))

ans = 0
for i, mod in enumerate(mods):
    ev = []
    for c, r in mod:
        c = (c-i) // d
        ev.append((c, 1))
        ev.append((c+r+1, -1))

    ev.sort()
    count = 0
    prev = -10**64
    for e in ev:
        size = e[0] - prev
        if count > 0:
            ans += size
        prev = e[0]
        count += e[1]

print(ans)
