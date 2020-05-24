#include <iostream>
#include <string>
#include<bits/stdc++.h>
using std::string;
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int len1=a.size();
  int len2=b.size();
  int len3=c.size();
  int dp[len1+1][len2+1][len3+1];
  memset(dp,0,sizeof(dp));
 /*for(int i=0;i<=len3;i++)
{
dp[0][0][i]=0;
}

for(int i=0;i<=len2;i++)
{
dp[0][i][0]=0;
}

for(int i=0;i<=len1;i++)
{
dp[i][0][0]=0;
}*/
for(int i=1;i<=len1;i++)
{
for(int j=1;j<=len2;j++)
{
for(int k=1;k<=len3;k++)
{
if (a[i-1]==c[k-1] and c[k-1]==b[j-1])
{
dp[i][j][k]=dp[i-1][j-1][k-1]+1;
}
else
{
dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j][k-1]),dp[i][j-1][k]);
}
}
}
}

  return dp[len1][len2][len3];
}
  

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
