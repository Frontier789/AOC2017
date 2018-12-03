import re

def conv(s):
    return list(map(int,re.split(",|: |x| @ |#|\n",s)[2:-1]))

with open('3a.in') as f:
    rcts = list(map(conv,f.readlines()))
    claims = [[0 for _ in range(0,2000)] for _ in range(0,2000)]
    for rct in rcts:
        for dx in range(0,rct[2]):
            for dy in range(0,rct[3]):
                claims[rct[0]+dx][rct[1]+dy]+=1
    
    overlaps = 0
    for a in claims:
        for b in a:
            if b > 1:
                overlaps += 1
    
    print(overlaps)