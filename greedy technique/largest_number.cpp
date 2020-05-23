#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;

bool comp(string X,string Y)
{
cout<<"X="<<X<<" "<<"Y="<<Y<<endl;
string XY=X.append(Y);
string YX=Y.append(X);
cout<<XY<<" "<<YX<<endl;
return XY.compare(YX)>0?1:0;
}

string largest_number(vector<string> a) {
  sort(a.begin(),a.end(),comp);
  /*std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;*/
  string d="";
  for(int i=0;i<a.size();i++)
{
d=d+a[i];
}
return d;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
