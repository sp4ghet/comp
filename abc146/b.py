n = int(input())
s = input()

begin = ord('A')
end = ord('Z')
modulo = end - begin + 1

ans = [(ord(c) - begin + n) % modulo for c in s]
ans = ''.join([chr(o + begin) for o in ans])

print(ans)
