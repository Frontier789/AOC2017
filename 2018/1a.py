with open('1a.in') as f:
    content = f.readlines()
    nums = list(map(int,content))
    print(sum(nums))