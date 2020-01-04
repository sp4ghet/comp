a, b, k = map(int, input().split())

fin_a = max(a-k, 0)
new_k = max(k-a, 0)

fin_b = max(b-new_k, 0)

print(fin_a, fin_b)
