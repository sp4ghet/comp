import operator as op
from functools import reduce

n = int(input())

ds = map(int, input().split(' '))
ds = list(ds)
modulus = 998244353


def prod(nums, start_value=1):
    result = start_value
    for num in nums:
        result *= num

    return result


# def ncr(n, r):
#     r = min(r, n-r)
#     numer = reduce(op.mul, range(n, n-r, -1), 1)
#     denom = reduce(op.mul, range(1, r+1), 1)
#     return numer / denom


def f(q, p):
    return q ** p
    # if q == 1:
    #     return 1
    # result = 0
    # for k in range(0, p+1):
    #     result += ncr(p, p-k) * f(q-1, p-k)
    # return result


q = ds.count(0)
if(q != 1):
    print(0)
    exit()

result = 1
for i in range(0, max(ds) + 1):
    if not i in ds:
        print(0)
        exit()

    p = ds.count(i+1)
    result *= f(q, p) % modulus
    q = p


print(int(result))
