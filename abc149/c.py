from math import ceil, sqrt
n = int(input())

if n == 2:
    print(2)
    exit()

n = n+1 if n % 2 == 0 else n

notPrime = True
while notPrime:
    notPrime = False
    for i in range(2, ceil(sqrt(n))):
        if n % i == 0:
            n += 2
            notPrime = True
            break


print(n)
