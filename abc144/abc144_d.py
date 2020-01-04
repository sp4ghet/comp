from math import atan, pi

a, b, x = map(int, input().split(' '))

h = x / a**2
if h > b / 2:
    tan_theta = 2*(b - h) / a
else:
    tan_theta = b**2 / (2*a*h)

theta = atan(tan_theta) * 180 / pi

print(theta)
