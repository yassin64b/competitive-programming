inp = lambda:map(int,input().split())
n, l, r = inp()
a = list(inp())
b = list(inp())

for i in range(l-1):
    if a[i] != b[i]:
        print("LIE")
        exit()
for i in range(r, n):
    if a[i] != b[i]:
        print("LIE")
        exit()


print("TRUTH")

