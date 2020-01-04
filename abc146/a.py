s = input()

weekdays = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']

idx = weekdays.index(s)

ans = 7 - (idx + 1) % len(weekdays)

print(ans)
