import os

dir = r"C:\Users\soham\Desktop\DSA\Languages\C++\C++ DSA\Array"

os.chdir(dir)
count = len(next(os.walk(dir))[2])

for f in os.listdir():
    num, f = f.split(" ")
    f, ext = f.split(".")
    print(f)
# os.rename(f, newName)
