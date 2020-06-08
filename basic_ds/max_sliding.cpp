#include <iostream>
#include <vector>
#include <deque>
#include <bits/stdc++.h>

using namespace std;

void max_sliding_window(vector<int> const & A,int w)
{
    deque<int>s;
  	vector<int> v;  
    for(int i=0;i<w;i++){
        
        while((!s.empty()) && A[s.back()]<=A[i])
        {
            s.pop_back();
        }
        s.push_back(i);
    }

    for(int i=w;i<A.size();i++)
    {
        cout<<A[s.front()]<<" ";
        while((!s.empty()) && s.front()<=(i-w))
        {
            s.pop_front();
        }
        while((!s.empty()) && A[s.back()]<=A[i])
        {
            s.pop_back();
        }
        s.push_back(i);
    }
    cout<<A[s.front()]<<endl;
   
 return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    
    max_sliding_window(A,w);

    return 0;
}
