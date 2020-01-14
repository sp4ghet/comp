import numpy as np
from numpy.linalg import norm
from math import sqrt
n = int(input())
points = np.zeros((n, 2))
for i in range(n):
    points[i] = list(map(float, input().split()))

d = 0
for i in range(n):
    for j in range(n):
        k = norm(points[i] - points[j])
        d = d if d > k else k

r = d/sqrt(3)
r = min([r, d/2])
print(r)
