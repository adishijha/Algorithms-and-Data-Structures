#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
using namespace std;

/*int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}*/


int get_majority_element(vector<int> &a, int left, int right)
{
int curelem=0;
int c=0;
int n=a.size();

for(int i=0;i<n;i++)
{
if(c==0)
{
curelem=a[i];
c=1;
}
else
{
if(curelem==a[i])
{
c=c+1;
}
else
{
c--;}
}
}
if (c==0)
{
return 0;
}
else
{
int f=count(a.begin(),a.end(),curelem);
if(f>=(int(n/2)+1))
{
return 1;
}
else
{
return 0;
}
}
}

/*int get_majority_element(vector<int> &a, int left, int right)
{
int n=a.size();
for(int i=0;i<(n-2);i=i+2)
{
if(a[i]==a[i+2])
{
return 1;
}
}
for(int i=0;i<(n-1);i++)
{
if( a[i]==a[i+1])
{
return 1;
}
}
return 0;
}*/


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size())) << '\n';
 // std::cout << (get_majority_element1(a, 0, a.size())) << '\n';
}
