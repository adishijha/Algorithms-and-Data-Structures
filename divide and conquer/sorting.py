# Uses python3
import sys
import random

def partition3(a, l, r):
    x=a[l]
    m1=l
    m2=l
    j=l
    for i in range(l+1,r+1):
        if a[i]<=x:
            j=j+1
            if a[i]<x:
                m1=m1+1
                m2=m2+1
            else:
                m2=m2+1
            a[j],a[i]=a[i],a[j]
    a[l],a[m1]=a[m1],a[l]
    print(a)
    print(m1,m2)
  
    if m1!=m2:
        i=l
        j=m1
        while j<=m2:
            if a[j]!=x:
                while a[i]!=x:
                    i=i+1
                a[i],a[j]=a[j],a[i]
            j=j+1
        d=[]
        d.append(m1)
        d.append(m2)
        print(a)
        return d
    d=[]
    d.append(m1)
    d.append(m1)
    return d

'''def partition2(a, l, r):
    x = a[l]
    j = l
    for i in range(l + 1, r + 1):
        if a[i] <= x:
            j += 1
            a[i], a[j] = a[j], a[i]
    a[l], a[j] = a[j], a[l]
    return j'''

def randomized_quick_sort1(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    print(k)
    a[l], a[k] = a[k], a[l]
    z=partition3(a, l, r)
    print(z)
    randomized_quick_sort(a, l, z[0]- 1);
    randomized_quick_sort(a, z[1]+ 1, r);

'''def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    #print(k)
    a[l], a[k] = a[k], a[l]
    #use partition3
    m = partition2(a, l, r)
    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);'''


if __name__ == '__main__':
    #flag=True
    n=int(input())
    a = list(map(int, input().strip().split(' ')))
    '''while flag:
        n=random.randint(1,100)
        print(n)
        a=[]
        for i in range(n):
            a.append(random.randint(1,1000)%100)
        print(a)  
        b=a[:]
        randomized_quick_sort1(a, 0, n - 1)
        randomized_quick_sort(b, 0, n - 1)
        if a!=b:
            print("Error")
            flag=False
            print(a)
            print(b)'''
    randomized_quick_sort1(a, 0, n - 1)    
    for x in a:
        print(x, end=' ')
