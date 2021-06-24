import os

dir = r"C:\Users\soham\Desktop\DSA\Languages\C++\C++ DSA"

os.chdir(dir)
count = len(next(os.walk(dir))[1])

for i, f in zip(range(1, count), os.listdir()):
    num, filename = f.split(" ")
    newName = str(i).zfill(2) + ". " + filename
    print(newName)
    os.rename(f, newName)
