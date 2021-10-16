T = int(input())

def manhatt(s, o):
    x,y = s
    
    dx = min(abs(x - o[0]),  abs(x - o[2]))
    dy = min(abs(y - o[1]),  abs(y - o[3]))
    if o[0] <= x <= o[2]:
        dx = 0
    if o[1] <= y <= o[3]:
        dy = 0
    return dx + dy

for case in range(1, T+1) :
    K = int(input())
    objs = []
    for _ in range(K):
        objs.append([int(a) for a in input().split()]) # x1, y1, x2, y2 
    s = objs[0][0],  objs[0][1]

    print([manhatt(s, o) for o in objs])
    Xs = [objs[]]
    x_min = 
    s = approach(s)
    print("Case #" + str(case) + ":", "YES")