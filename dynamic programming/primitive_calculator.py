# Uses python3
import sys

def optimal_sequence(n):
    dp=[float('inf') for i in range(n+1)]
    dp[0]=0
    dp[1]=0
    dp[2]=1
    dp[3]=1
    num=[1]*(n+1)
    for i in range(2,n):
        if (i+1)<=n:
            if dp[i+1]>dp[i]+1:
                dp[i+1]=dp[i]+1
                num[i+1]=i
        if (2*i)<=n:
            if dp[2*i]>dp[i]+1:
                dp[2*i]=dp[i]+1
                num[2*i]=i
        if (3*i)<=n:
            if dp[3*i]>dp[i]+1:
                dp[3*i]=dp[i]+1
                num[3*i]=i
        '''for i in range(n+1):
            print(dp[i],end=' ')
        print()'''
    d=[]
    d.append(n)
    #print(num)
    pos=num[n]
    for i in range(dp[n]):
        d.append(pos)
        if pos==1:
            break
        pos=num[pos]
    #print(d) 
    return d

n = int(input())
if n==1:
    print(0)
    print(1)
elif n==2 or n==3:
    print(1)
    print(1, n)
else:
    
    sequence = list(optimal_sequence(n))
    print(len(sequence) - 1)
    sequence=reversed(sequence)
    for x in sequence:
        print(x, end=' ')
