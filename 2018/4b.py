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
    mxi,mxid,mxv = 0,0,0
    for l in evs:
        if l[6] == 'Guard':
            id = int(l[7][1:])
        if l[6] == 'falls':
            fall = int(l[4])
        if l[6] == 'wakes':
            if id not in sleps:
                sleps[id] = {}
            for i in range(fall,int(l[4])):
                if i not in sleps[id]:
                    sleps[id][i] = 1
                sleps[id][i] += 1
                if sleps[id][i] > mxv:
                    mxv = sleps[id][i]
                    mxi = i
                    mxid = id
    
    print(mxi*mxid)