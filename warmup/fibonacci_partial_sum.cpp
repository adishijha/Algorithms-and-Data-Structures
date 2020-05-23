#include <iostream>
#include <vector>
using namespace std;
using std::vector;

/*long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum =(sum+current)%10;
        }

        long long new_current = next;
        next = (next + current)%10;
        current = new_current;
    }

    return sum % 10;
}*/

int get_fibonacci_partial_sum(long long from, long long to) {

    long long sum  = 0;
    long long sumt  = 1;
    long long F[60]; F[0]=0;F[1]=1;
    long d=(from/60);
     from=from%60;
     to=to-(60*d);

       if (from== 0 and to==0)
        	return 0;
       if (from== 0 and to==1)
        	return 1;
       if(from==0 or from==1)
{
sum=1;
}
	for(int i=2;i<60;i++)
	{
		F[i]=(F[i-1]+F[i-2])%10;
		sumt=(sumt+F[i])%10;
		if(i>=from and i<=to)
			{sum=(sum+F[i])%10;}
		
		if(i==to)
			{
			return sum;
			}
	}
       to=to-60;
       long c=(to)/60;
	sum=(sum+(sumt*c))%10;
       long rem=to%60;
	if (rem <= 1)
        	return (sum+rem);
	else

		{ 
			sum=sum+1;
 			for (long long i = 2; i <=rem; ++i)
				 {
            			sum=(sum+F[i])%10;
    				}
		return sum; 
		}

}


int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
