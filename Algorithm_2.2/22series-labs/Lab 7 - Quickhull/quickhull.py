import math

global res
res = []

def findSide(p1,p2,p):
    val = (p[1] - p1[1]) * (p2[0] - p1[0]) - (p2[1] - p1[1]) * (p[0] - p1[0])
    if val > 0: return 1
    elif val < 0: return -1
    else: return 0

def farthest(set,p1,p2):
    d = 0
    p = ()
    for i in set:
        dis = abs((p2[0]-p1[0])*(p1[1]-i[1])-(p1[0]-i[0])*(p2[1]-p1[1])) / math.sqrt((p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]))
        if dis > d: 
            d = dis
            p = i
    return p

def findhull(p,p1,p2):
    if not p: return
    far = farthest(p,p1,p2)
    leftset = []
    rightset = []
    for i in p:
        if findSide(p1,p2,i) == 1: rightset.append(i)
        elif findSide(p1,p2,i) == -1: leftset.append(i)
    lefthull = findhull(leftset,p1,far)
    righthull = findhull(rightset,far,p2)
    if far: res.append(far)
    if lefthull: res.append(lefthull)
    if righthull: res.append(righthull)

def quick_hull(p):
    if len(p) < 3: return
    p1 = sorted(p, key = lambda x: x[0])[0]
    p2 = sorted(p,reverse=True, key = lambda x: x[1])[0]
    leftset = []
    rightset = []
    for i in p:
        if findSide(p1,p2,i) == 1: rightset.append(i)
        elif findSide(p1,p2,i) == -1: leftset.append(i)
    lefthull = findhull(leftset,p1,p2)
    righthull = findhull(rightset,p2,p1)
    if p1: res.append(p1)
    if p2: res.append(p2)
    if lefthull: res.append(lefthull)
    if righthull: res.append(righthull)

p = [(0,0),(0,10),(5,5),(5,-5),(2,2),(2,-2)]
print(p)
quick_hull(p)
if (len(res) < 3):
    print("Hull not possible")
else:
    print(res)