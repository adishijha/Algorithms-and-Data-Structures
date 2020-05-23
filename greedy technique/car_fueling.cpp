#include <iostream>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int n=stops.size();
    if ((dist)<=tank)
	{
		return 0;
	}
   int last=0,cur=0,i=0,c=0;
   while(i<n)
	{
		while((stops[i+1]-last)<=tank and ((i+1)<n))
			{
				cur=i+1;
				i=i+1;
			}
		if(last==stops[cur])
			{
				return -1;
			}
		c=c+1;
		if(dist-stops[cur]<=tank)
			{
				return c;
			}
               if(i==n-1)
			{
				return -1;
			}
		
                last=stops[cur];
	     // cout<<"last"<<" "<<"cur"<<" "<<"c"<<endl;

              // cout<<last<<" "<<stops[cur]<<" "<<c<<endl;

	}
     
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops;
    int input;
    stops.push_back(0);
    
    for (size_t i = 0; i < n; ++i)
{
        cin>>input;
        stops.push_back(input);
}
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
