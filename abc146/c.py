a, b, x = map(int, input().split())


def predicate(n):
    return x >= a*n + b*len(str(n))


n = 0
while predicate(n):
    n = max(1, 10*n)


def binary_search(left, right):
    low = left
    high = right

    while low <= high:
        mid = (low + high) // 2
        if predicate(mid) and predicate(mid) != predicate(mid + 1):
            return mid
        if predicate(mid):
            low = mid + 1
        else:
            high = mid - 1

    return None


ans = binary_search(n//10, n)
if ans is None:
    ans = 0
ans = min(10**9, ans)

print(ans)
