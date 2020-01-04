from functools import reduce
n = int(input())

div_rem = [(n / i, n % i) for i in range(1, 10)]


def reducer(acc, x):
    return acc or (x[1] == 0 and x[0] <= 9)


possible = reduce(reducer, div_rem, False)


print('Yes') if possible else print('No')
