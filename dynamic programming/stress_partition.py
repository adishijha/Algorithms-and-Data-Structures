import sys
import itertools
import random
def partition(start,a,used,k,obtainedsum,reqsum):
    if k==1:
        return True
    elif obtainedsum==reqsum:
        return partition(0,a,used,k-1,0,reqsum)
    else:
        for i in range(start,len(a)):
            if used[i]==False and obtainedsum+a[i]<=reqsum:
                used[i]=True
                if partition(i+1,a,used,k,obtainedsum+a[i],reqsum):
                    return True
                else:
                    used[i]=False
        return False
                


def partition3(A):
    for c in itertools.product(range(3), repeat=len(A)):
        sums = [None] * 3
        for i in range(3):
            sums[i] = sum(A[k] for k in range(len(A)) if c[k] == i)

        if sums[0] == sums[1] and sums[1] == sums[2]:
            return 1

    return 0

if __name__ == '__main__':
    '''n=int(input())
    A = list(map(int, input().split()))'''
    flag=True
    while flag:
        n=15
        #print(n)
        a=[]
        for i in range(n):
            a.append(random.randint(1,1000)%100)
        d=sum(a)
        if d%3!=0 or n<=2:
            print(0)
        else:
            print(a)  
            b=a[:]
            reqsum=d//3
            obtainedsum=0
            used=[False for i in range(n)]
            q=partition(0,a,used,3,obtainedsum,reqsum)
            g=0
            if q:
                g=1
            else:
                g=0
            p=partition3(a)
            if p!=g:
                print("Error")
                flag=False
                #print(p)
                print("correct ",p)
    '''d=sum(A)
    if d%3!=0 or n<=2:
        print(0)
    else:
        a=reversed(sorted(A))
        #print(partition3(A))
        print(partition(A,d))'''

