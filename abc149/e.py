from bisect import bisect_left
from itertools import accumulate

n, m = map(int, input().split())
hands = [int(x) for x in input().split()]
increasing = sorted(hands)
hands = list(reversed(increasing))
xs = [0] + list(accumulate(hands))

max_x = 2 * 10**5 + 1
min_x = 0


def canGet(x):
    count = 0
    for hand in increasing:
        idx = bisect_left(increasing, x-hand)
        count += n - idx
    return count >= m


while max_x - min_x > 1:
    # left
    mid = (max_x + min_x) // 2
    if canGet(mid):
        min_x = mid
    else:
        max_x = mid

ans = 0
count = 0

for Ai in hands:
    idx = bisect_left(increasing, min_x-Ai)
    ans += Ai*(n-idx) + xs[n-idx]
    count += n-idx
print(ans-(count-m)*min_x)
