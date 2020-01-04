s = input()

size = len(s)
if size % 2 != 0:
    size += 1

size = size // 2

ans = 0
for i in range(size):
    ans += 0 if s[i] == s[-(i+1)] else 1

print(ans)
