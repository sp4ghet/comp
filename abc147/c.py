from itertools import combinations
n = int(input())

testimonies = []
for i in range(n):
    A_i = int(input())
    testimonies.append([])
    for j in range(A_i):
        x_ij, y_ij = map(int, input().split())
        testimonies[i].append([x_ij-1, y_ij])

for i in range(n):
    i = n - i  # start with largest
    contradiction = True
    for honests in combinations(range(n), i):
        contradiction = False
        for testimony in [testimonies[j] for j in honests]:
            for x, y in testimony:
                if (y == 1 and x not in honests) or (y == 0 and x in honests):
                    contradiction = True
                    break
        if not contradiction:
            print(i)
            exit()

print(0)
