from math import floor
a, b = input().split()
a = int(a)
b = int(b[0])*100 + int(b[2])*10 + int(b[3])
ans = (a*b) // 100
print(ans)
