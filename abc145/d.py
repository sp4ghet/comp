from math import factorial
pos = map(int, input().split())

x, y = sorted(pos)

num_twos = x // 2
rem = x % 2

solution = 0

max_n = 10**6

result = max_n*[None]
inverse = max_n*[None]
result[0] = 1
inverse[0] = 1

m = 10**9 + 7
for i in range(1, max_n):
    result[i] = (i*result[i-1]) % m
    inverse[i] = result[i]**(m-2) % m


def ncr(n, r):
    print(result[n], inverse[r])
    return (result[n] * inverse[r] * inverse[n-r]) % m


while not (y == num_twos + (rem*2)):
    num_twos -= 1
    rem += 2

    if y < (num_twos + rem*2):
        print(0)
        exit()

solution = ncr(num_twos + rem, rem)

print(int(solution))
