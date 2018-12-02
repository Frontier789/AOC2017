from collections import Counter

with open('2a.in') as f:
    threes = 0
    twos = 0
    for l in f.readlines():
        has3 = False
        has2 = False
        for a,i in Counter(l).items():
            has3 = has3 or i == 3
            has2 = has2 or i == 2
        threes += int(has3)
        twos += int(has2)
    print(threes*twos)