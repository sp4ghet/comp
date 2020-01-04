n = int(input())
ds = map(int, input().split())
ds = list(ds)

acc = 0
for i in range(0, len(ds)):
    for j in range(i+1, len(ds)):
        acc += ds[i]*ds[j]

print(acc)
