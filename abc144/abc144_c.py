from math import sqrt, ceil
n = int(input())

distance = 10**13
for i in range(1, ceil(sqrt(n)) + 1):
    if n % i == 0:
        new_distance = n//i + i
        if new_distance < distance:
            distance = new_distance

print(distance - 2)
