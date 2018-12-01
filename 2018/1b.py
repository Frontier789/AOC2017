with open('1a.in') as f:
    content = f.readlines()
    nums = list(map(int,content))
    val = 0
    s = {0}
    while True:
        for i in nums:
            val += i
            if s.issuperset({val}):
                print(val)
                exit(0)
            s.add(val)