global A

def merge(l,m,r):
    a = l
    b = l+m
    temp = []
    while a < l+m and b < l+m+m:
        if A[a] < A[b]:
            temp.append(A[a])
            a += 1
        else:
            temp.append(A[b])
            b += 1
    while a < l+m:
        temp.append(A[a])
        a += 1
    while b < l+m+m:
        temp.append(A[b])
        b += 1
    
    j = 0
    for i in range(l,l+m+m):
        A[i] = temp[j]
        j += 1
    
    a = l
    b = l+m+m
    temp.clear()
    while a < l+m+m and b < r:
        if A[a] < A[b]:
            temp.append(A[a])
            a += 1
        else:
            temp.append(A[b])
            b += 1
    while a < l+m+m:
        temp.append(A[a])
        a += 1
    while b < r:
        temp.append(A[b])
        b += 1
    
    j = 0
    for i in range(l,r):
        A[i] = temp[j]
        j += 1

def merge_sort(l,r):
    if r - l == 1:
        return
    elif r - l == 2: 
        if A[r-1] < A[l]:
            A[l], A[r-1] = A[r-1], A[l]
        return
    m = (r-l) // 3
    merge_sort(l,l+m)
    merge_sort(l+m,l+m+m)
    merge_sort(l+m+m,r)
    merge(l,m,r)

A = [7,10,5,12,18,6,2,44,22,67]
merge_sort(0,10)
print(A)