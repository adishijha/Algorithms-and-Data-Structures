#include <iostream>
#include<ctime>
using namespace std;
/*int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
*/


int gcd(int a,int b)
{
while(b!=0)
{
int c=a%b;
a=b;
b=c;
}
return a;
}


int main() {
time_t current_time1,current_time2;
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
