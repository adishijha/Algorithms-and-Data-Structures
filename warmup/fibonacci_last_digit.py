# Uses python3
#pisano's period
import sys

def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n
    F=[0 for i in range(60)]
    F[0]=0
    F[1]=1
    for i in range(2,60):
        F[i]=(F[i-1]%10+F[i-2]%10)%10
    d=n%60
    return F[d]
	
if __name__ == '__main__':
    n = int(input())
    print(get_fibonacci_last_digit_naive(n))
