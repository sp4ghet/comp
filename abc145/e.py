n,t = map(int, input().split())

dishes = []
for i in range(n):
    time, delic = map(int, input().split())
    rate = delic/time
    dishes.append([time, delic, rate])


dishes = sorted(dishes, key=lambda dish: -dish[2])
max_delic = max(dishes, key=lambda d: d[1])
dishes.remove(max_delic)
print(dishes)

total_delic = 0
elapsed = 0
print()
for i,dish in enumerate(dishes):
    if elapsed + dish[0] >= t-1:
        total_delic += max_delic[1]
        break
    total_delic += dish[1]
    elapsed += dish[0]

print(total_delic)
