import sys
sys.setrecursionlimit(100000000)
n, runner, chaser = map(int, input().split())
runner -= 1
chaser -= 1
if runner == chaser:
    print(0)
    exit()

tree = [[] for _ in range(n)]
for i in range(n-1):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].append(b)
    tree[b].append(a)

def dfs(dists, start, d=0, p=-1):  
    dists[start] = d
    for neighbor in tree[start]:
        if neighbor == p:
            continue
        dfs(dists, neighbor, d+1, start)

def dist(start):
    dists = [0 for _ in range(n)]
    dfs(dists, start)
    return dists

furthest = 0
run_dist = dist(runner)
chs_dist = dist(chaser)
for i in range(n):
    if run_dist[i] < chs_dist[i]:
        furthest = max(furthest, chs_dist[i])

ans = furthest-1

print(ans)