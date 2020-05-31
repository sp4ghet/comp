def med(a):
    n = len(a)
    a = sorted(a)
    if(n % 2 == 0):
        return ((a[n//2 - 1] + a[n//2]) / 2)

    return a[(n)//2]


low = [1, 2]
high = [2, 3]
print(med(low))
print(med(high))
print(med(high) - med(low))
