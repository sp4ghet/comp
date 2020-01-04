n, k = map(int, input().split())
r, s, p = map(int, input().split())
t = input()

subGames = [[] for _ in range(k)]

pattern = {'r': p, 's': r, 'p': s, '': 0}
win = {'r': 'p', 's': 'r', 'p': 's'}

subPts = [0 for _ in range(k)]
for i, hand in enumerate(t):
    subGame = subGames[i % k]
    winPt = pattern[hand]
    winHand = win[hand]
    if subGame and win[hand] == subGame[-1]:
        winPt = 0
        winHand = t[i+k] if i+k < n else hand

    subGame.append(winHand)
    subPts[i % k] += winPt

ans = sum(subPts)

print(ans)
