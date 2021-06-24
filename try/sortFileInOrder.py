import os

dir = r"C:\Users\soham\Desktop\DSA\Languages\C++\C++ DSA\09. Recursion\Recursion - 5 - Advance Recursion"

os.chdir(dir)
count = len(next(os.walk(dir))[2])

for i, f in zip(range(1, count), os.listdir()):
    newName = str(i).zfill(2) + ". " + f
    print(newName)
    # os.rename(f, newName)
