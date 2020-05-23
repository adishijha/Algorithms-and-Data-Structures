#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
using std::vector;

bool rev(const pair<float,float>&a,const pair<float,float>&b)
{
return double(a.first/a.second)>double(b.first/b.second);
}

double get_optimal_value(int capacity,vector<pair<float,float>>v) {
  double value = 0.0;
 int n=v.size();
for(int i=0;i<n;i++)
{
if(v[i].second<capacity)
{
value=value+v[i].first;
capacity=capacity-v[i].second;
}
else
{
double a=(v[i].first/v[i].second)*capacity;
value=value+a;
break;
}
}
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<float> values(n);
  vector<float> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  vector<pair<float,float>> v;
  for(int i=0;i<n;i++)
{
v.push_back(make_pair(values[i],weights[i]));
}
sort(v.begin(),v.end(),rev);
 

  double optimal_value = get_optimal_value(capacity, v);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
