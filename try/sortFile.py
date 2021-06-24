import os

dir = r"E:\Series\Beyblade\Beyblade Metal Masters"

os.chdir(dir)

count = len(next(os.walk(dir))[2])

for i, f in zip(range(1, count+1), os.listdir()):
    fileName = f.split(' ')
    newName = str(i).zfill(2) + ". " + ' '.join(fileName[1:])
    print(newName)
    # os.rename(f, newName)
