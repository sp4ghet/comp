from bisect import bisect_left
n = int(input())
ls = map(int, input().split())
ls = sorted(ls)

counter = 0
for i in range(n-2):
    for j in range(i+1, n-1):
        counter += (bisect_left(ls, ls[i] + ls[j]) - 1) - j

print(counter)
