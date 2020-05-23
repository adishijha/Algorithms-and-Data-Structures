#include <iostream>
#include<algorithm>
using namespace std;



long long lcm(long long a,long long b)
{
long long prod=a*b;
while(b!=0)
{
long long c=a%b;
a=b;
b=c;
}
return (prod/a);
}


int main() {
  int a, b;
  std::cin >> a >> b;
  
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}

