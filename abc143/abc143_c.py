n = int(input())
s = input()

prev = ''
counter = 0
for c in s:
    if prev != c:
        counter += 1
    prev = c

print(counter)
