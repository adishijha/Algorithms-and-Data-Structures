#include <iostream>

int get_change(int m) {
if( m<=0)
{
return 0;
}
  int n;
  int c10=m/10;
  int c5=(m-(c10*10))/5;
  int c1=(m-(c10*10)-(c5*5));
  n=c10+c5+c1;

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
