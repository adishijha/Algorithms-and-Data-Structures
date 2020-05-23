#Uses python3
import sys
def optimal_summands (n):
    u=n
    prev = 0
    s= 0
    l=[]
    for i in range (1, n + 1):
        if (n-i)>i:
            n=n-i
            s=s+i
            yield i
        else:
            x=u-s
            yield x
            break

if __name__ == '__main__':
    n = int (input ())
    summands =list(optimal_summands (n))
    print (len (summands)) 
    for x in summands:
	    print (x, end = ' ')

