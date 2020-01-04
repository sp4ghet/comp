import sys
sys.setrecursionlimit(100000000)
n = int(input())

tree = [[] for _ in range(n)]
edges = []
for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].append((b, i))
    tree[b].append((a, i))

ans = [None for _ in range(n-1)]
used = [False for _ in range(n)]
k = 0


def dfs(node, col=-1, parent=-1):
    global k
    if k < len(tree[node]):
        k = len(tree[node])

    c = 1
    for neighbor, i in tree[node]:
        if neighbor == parent:
            continue
        if c == col:
            c += 1
        ans[i] = c
        c += 1
        dfs(neighbor, ans[i], node)


dfs(0)

print(k)
for a in ans:
    print(a)
