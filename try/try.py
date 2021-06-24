from functools import reduce
import operator
arr = [1, 2, 3]
n = len(arr)
end = n//2
min_l = arr[:end]
max_l = arr[:end - 1:-1]

print(max_l)
print(min_l)
s = reduce(operator.add, zip(max_l, min_l))

for i in s:
    print(i, end=" ")
