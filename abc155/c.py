from collections import Counter
N = int(input())
S = []
for i in range(N):
    S.append(input())
A = []
d = Counter(S)
md = d.most_common(1)[0][1]

for key, value in d.items():
    if value == md:
        A.append(key)

As = sorted(A)
for a in As:
    print(a)
