n, k = map(int, input().split())
s = input()
initial_happiness = 0
left = 'X'
for c in s:
    initial_happiness += 1 if c == left else 0
    left = c
ans = min(n-1, initial_happiness + 2*k)
print(ans)
