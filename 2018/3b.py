import re

def conv(s):
    return list(map(int,re.split(",|: |x| @ |#|\n",s)[1:-1]))

with open('3a.in') as f:
    rcts = list(map(conv,f.readlines()))
    claims = [[0 for _ in range(0,2000)] for _ in range(0,2000)]
    overlaps = set()
    for rct in rcts:
        for dx in range(0,rct[3]):
            for dy in range(0,rct[4]):
                x,y = rct[1]+dx,rct[2]+dy
                if claims[x][y] != 0:
                    overlaps.add(claims[x][y])
                    overlaps.add(rct[0])
                else:
                    claims[x][y] = rct[0]
    
    print(set(range(1,rcts[-1][0]+1)).difference(overlaps))