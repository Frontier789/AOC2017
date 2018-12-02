with open('2a.in') as f:
    lines = f.readlines()
    for l1 in lines:
        for l2 in lines:
            if sum(c1 != c2 for c1, c2 in zip(l1, l2)) == 1:
                print("".join([c1 for c1, c2 in zip(l1, l2) if c1==c2 and c1!='\n']))
                exit(0)