def find_first_unique_char(inp):
    vis = dict()
    for c in inp:
        vis[c] = vis.get(c, 0) + 1
    for c in inp:
        if vis[c] == 1:
            print("The first non-repeating char is", c)
            return
    print("There are no non-repeating chars in the input")

find_first_unique_char(input())
