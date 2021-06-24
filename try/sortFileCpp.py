import os

dir = r"C:\Users\soham\Desktop\DSA\Languages\C++\Searching"

os.chdir(dir)

count = len(next(os.walk(dir))[2])


def flatten(list_of_lists):
    if len(list_of_lists) == 0:
        return list_of_lists
    if isinstance(list_of_lists[0], list):
        return flatten(list_of_lists[0]) + flatten(list_of_lists[1:])
    return list_of_lists[:1] + flatten(list_of_lists[1:])


for i, f in zip(flatten([[i]*2 for i in range(1, count//2+1)]), os.listdir()):
    num, fileName = f.split(' ')
    newName = str(i).zfill(2) + ". " + fileName
    print(newName)
    os.rename(f, newName)
