n = int(input())
s = input()

if n % 2 != 0:
    print('No')
    exit()

mid = n // 2

t1 = s[0:mid]
t2 = s[mid:]

print('Yes') if t1 == t2 else print('No')
