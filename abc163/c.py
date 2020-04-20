n = int(input())
a = map(int, input().split())

ans = [0] * n
for i in a:
    ans[i] += 1

for i in range(n):
    print(ans[i])
