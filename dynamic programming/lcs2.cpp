#include <iostream>
#include <string>
#include<bits/stdc++.h>
using std::string;
using namespace std;



int lcs2(vector<int> &a, vector<int> &b) {
  int len1=a.size();
  int len2=b.size();
  int dp[len2+1][len1+1];
  memset(dp,0,sizeof(dp));
 for(int i=0;i<=len1;i++)
{
dp[0][i]=0;
}


for(int i=0;i<=len2;i++)
{
dp[i][0]=0;
}

for(int i=1;i<=len1;i++)
{
for(int j=1;j<=len2;j++)
{
if (a[i-1]==b[j-1])
{
dp[j][i]=dp[j-1][i-1]+1;
}
else
{
dp[j][i]=max(dp[j-1][i],dp[j][i-1]); //we omit one value
}
}
}
/*  for(int i=0;i<=len2;i++)
{
for(int j=0;j<=len1;j++)
{
cout<<dp[i][j]<<" ";

}
cout<<endl;
}
cout<<endl;*/
  return dp[len2][len1];
}
  


int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
