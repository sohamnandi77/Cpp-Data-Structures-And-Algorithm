import os

dir = r"C:\Users\soham\Desktop\DSA\Languages\C++\C++ Algorithms\Sorting"

os.chdir(dir)

count = len(next(os.walk(dir))[2])

for f in os.listdir():
    num, fileName = f.split(' ')
    newName = fileName
    # print(newName)
    os.rename(f, newName)
