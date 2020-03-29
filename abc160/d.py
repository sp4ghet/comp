n, x, y = map(int, input().split())

g = [[1000000000 for j in range(n)] for i in range(n)]
x -= 1
y -= 1


for i in range(n):
    for j in range(n):
        a = min(i, j)
        b = max(i, j)

        d = min(b-a,  abs(y-b) + abs(x-a) + 1)
        g[i][j] = d
        g[j][i] = d


ds = [0 for _ in range(n)]

for i in range(n):
    for j in range(n):
        d = g[i][j]
        ds[d] += 1


for i in range(1, n):
    print(ds[i]//2)
