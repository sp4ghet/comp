from itertools import permutations

a = [8, 6, 9, 1, 2, 1]
n = len(a)

ans = 0
pos = set()
for x in permutations(range(n)):
    now = 0
    for i in range(n):
        now += a[i] * abs(x[i] - i)

    pos.add(now)
    here = [0]*n
    for i in range(n):
        here[x[i]] = a[i]
    if(now == 78):
        print(here)
        print("")

    ans = max(ans, now)

print(len(pos))
print(pos)

print(ans)
