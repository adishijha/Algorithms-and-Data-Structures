#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
int get_change(int m) {
  int c[]={1,3,4};
int dp[m+1];

dp[0]=0;
 
for(int i=1;i<=m;i++)
{
dp[i]=INT_MAX;
}

for(int i=0;i<3;i++)
{
for(int j=c[i];j<=m;j++)
{
dp[j]=min(dp[j],dp[j-c[i]]+1);

}
}


return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
