s = "aabbccddeeeddccbbaa"

l = [0]*256
n = len(s)


def removeIth(str):


for i in range(n):
    l[ord(s[i])] += 1

for i in range(256):
    if(l[i] > 0):
        # * even
        if(l[i] % 2 == 0):
            count = l[i]//2

    # * odds
    else:
        print(chr(i))
        count2 = l[i]//2
        print(count2)
        curr2 = 0
        for j in range(0, n):
            if(s[j] == chr(i)):
                curr2 += 1
            if(curr2 == count2 + 1):
                print(j)
                s = s[:j] + s[j+1:]
