N = int(input())

counts = [[0 for _ in range(10)] for _ in range(10)]
# keep a record of numbers whose first digit is `first` and last digit is `last`
for i in range(1, N+1):
    first = int(str(i)[0])
    last = int(str(i)[-1])

    counts[first][last] += 1

ans = 0
for i in range(1, 10):
    for j in range(1, 10):
        ans += counts[i][j] * counts[j][i]

print(ans)
