
n = int(input())
a = map(int, input().split())
a = list(a)

c = {}
for k in a:
    if c.get(k) is None:
        c[k] = 1
    else:
        c[k] += 1


def nc2(x):
    return (x*(x-1)) // 2


ans = 0
for cn in c.values():
    ans += nc2(cn)

for k in a:
    diff = c[k]-1
    print(ans - diff)
