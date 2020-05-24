#include <iostream>
#include <string>
#include<bits/stdc++.h>
using std::string;
using namespace std;
int edit_distance(const string &str1, const string &str2) {
  int len1=str1.length();
  int len2=str2.length();
  int dp[len2+1][len1+1];
  memset(dp,0,sizeof(dp));
 for(int i=0;i<=len1;i++)
{
dp[0][i]=i;
}


for(int i=0;i<=len2;i++)
{
dp[i][0]=i;
}

for(int i=1;i<=len1;i++)
{
for(int j=1;j<=len2;j++)
{
if (str1[i-1]==str2[j-1])
{
dp[j][i]=dp[j-1][i-1];
}
else
{
dp[j][i]=min(min(dp[j-1][i],dp[j-1][i-1]),dp[j][i-1])+1;
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
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
