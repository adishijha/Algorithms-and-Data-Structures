#include <iostream>
using namespace std;

/*long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }

    return current % m;
}*/

long long get_fibonacci_huge(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
long long tmp_previous;
    int len;

    for (int i = 0; i <(m*m) ; ++i) {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
        if(previous==0 and current==1)
		{
			len=i+1;
			break;
		}
    }
  //cout<<len<<endl;
	n=n%len;
     previous = 0;
     current  = 1;
if(n<=1)
{
return n;
}
 for(int i=0;i<=(n-2);i++)
{
  	tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
}

    return current % m;
}


int main() {
    long long n, m;
    std::cin >> n >> m;
   // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
