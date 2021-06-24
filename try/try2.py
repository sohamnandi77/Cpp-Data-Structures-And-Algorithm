# 550 = 10

# x = input()
# y = input()

l = [1]
s = l[::]
n = len(l)
if (n % 2 == 0):
    mid = (n // 2) - 1
else:
    mid = (n // 2)

j = 0
for i in range(n-1, mid, -1):
    s[j] = l[i]
    j += 2

j = 1
for i in range(0, mid):
    s[j] = l[i]
    j += 2

s[-1] = l[mid]

print(s, end=" ")
