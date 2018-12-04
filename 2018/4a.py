import re

def conv(s):
    return re.split("\[|-| |:|\]",s)[1:-1]

with open('4a.in') as f:
    evs = []
    for l in map(conv,f.readlines()):
        evs.append(l)
    evs.sort()
    id = 0
    sleps = {}
    fall = 0
    for l in evs:
        if l[6] == 'Guard':
            id = int(l[7][1:])
        if l[6] == 'falls':
            fall = int(l[4])
        if l[6] == 'wakes':
            if id in sleps:
                sleps[id].append((fall,int(l[4])))
            else:
                sleps[id] = [(fall,int(l[4]))]
    
    _,id = max([(sum([y-x for x,y in sleps[k]]),k) for k in sleps])
    alv = [0]*60
    for x,y in sleps[id]:
        for i in range(x,y):
            alv[i] += 1
    
    _,mn = (max([(alv[i],i) for i in range(0,60)]))
    
    print(mn*id)