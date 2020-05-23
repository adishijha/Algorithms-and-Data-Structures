#include <iostream>
using namespace std;
/*int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum =(sum+ current)%10;
    }

    return sum % 10;
}
*/
int fibonacci_sum(long long n) {
    if (n <= 1)
        return n;

    long long sum  = 1;
    long long F[60]; F[0]=0;F[1]=1;
	for(int i=2;i<60;i++)
	{
		F[i]=(F[i-1]+F[i-2])%10;
		sum=(sum+F[i])%10;
		if(i==n)
{
return sum;
}
	}
       int c=(n)/60;
	sum=(sum*c)%10;
       int rem=n%60;
	if (rem <= 1)
        	return (sum+rem);
	else
{ sum=sum+1;
 	for (long long i = 2; i <=rem; ++i) {
            sum=(sum+F[i])%10;
    				}
	return sum; 


}

}


int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n)<<endl;
    std::cout << fibonacci_sum(n);
}
