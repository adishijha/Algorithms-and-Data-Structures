# Uses python3
def evalt(a, op, b):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
def getmaxmin(exp,opr,i,j,M,m):
    mi= float('inf')
    mx= float('-inf')
    for k in range(i,j):
        #print(type(M[i][k]),type(opr[k]),type(M[k+1][j]))
        a=evalt(M[i][k],opr[k],M[k+1][j])
        b=evalt(M[i][k],opr[k],m[k+1][j])
        c=evalt(m[i][k],opr[k],M[k+1][j])
        d=evalt(m[i][k],opr[k],m[k+1][j])
        #print(type(a))
        #print(type(mi))
        mi=min(mi,a,b,c,d)
        mx=max(mx,a,b,c,d)
        #print(mi,mx,a,b,c,d)
    d=[]
    d.append(mx)
    d.append(mi)
    #print(d)
    return d
def get_maximum_value(dataset):
    dataset=list(dataset)
    l=len(dataset)
    n=int((l+1)/2)
    op=l//2
    exp=[0]*(n+1)
    opr=[0]*(op+1)
    exp[0]=0
    opr[0]=0
    c=1
    for i in range(0,l-1,2):
        exp[c]=int(dataset[i])
        opr[c]=dataset[i+1]
        c=c+1
    exp[c]=int(dataset[l-1])
    #print(exp)
    #print(opr)
    
    M=[[0 for i in range(n+1)] for j in range(n+1)]
    m=[[0 for i in range(n+1)] for j in range(n+1)]
    for i in range(1,n+1):
        M[i][i]=exp[i]
        m[i][i]=exp[i]
    for s in range(1,n):
        for i in range(1,n-s+1):
            j=i+s
            z=getmaxmin(exp,opr,i,j,M,m)
            M[i][j]=z[0]
            m[i][j]=z[1]
    #print(M)
    return M[1][n]


if __name__ == "__main__":
    print(get_maximum_value(input()))
