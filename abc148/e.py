n = int(input())

def solve(n):
    if n % 2 != 0:
        return 0
    div = 10
    sol = 0
    term = n // div
    while term > 0:
        term = n // div
        sol += term 
        div *= 5
    return sol

print(solve(n))