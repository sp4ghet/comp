from itertools import permutations
from math import sqrt, factorial
n = int(input())

towns = []
for i in range(n):
    towns.append(list(map(int, input().split())))

perms = permutations(towns)

sum_dists = 0
for path in list(perms):
    for i in range(n-1):
        dist = sqrt((path[i+1][0] - path[i][0])**2 +
                    (path[i+1][1] - path[i][1])**2)
        sum_dists += dist

print(sum_dists / factorial(n))
