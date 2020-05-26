#include <iostream>
#include <vector>
using namespace std;
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  int n=w.size();
  int dp[2][W+1];
  for(int i=0;i<=W;i++)
{
dp[0][i]=0;
dp[1][i]=0;
}


for(int i=0;i<n;i++)
{
for(int j=1;j<=W;j++)
{
if (w[i]>j)
{
dp[(i+1)%2][j]=dp[i%2][j];
}
else
{
dp[(i+1)%2][j]=max(dp[i%2][j],dp[i%2][j-w[i]]+w[i]);
}
}
}
/*for(int i=0;i<2;i++)
{
for(int j=0;j<=W;j++)
{
cout<<dp[i][j]<<" ";
}
cout<<endl;
}

*/
if(n%2==1)
{
return dp[1][W];
}
return dp[0][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
