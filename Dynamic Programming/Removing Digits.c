n = int(input())
p = 0

while n != 0:
    nstr = str(n)
    znamenke = []
    
    for i in nstr:
        znamenke.append(int(i))
    #print(znamenke)
    znamenke.sort()
    
    n -= znamenke[len(znamenke)-1]
    p += 1

print(p)