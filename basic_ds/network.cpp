#include<bits/stdc++.h>
#include<deque>
using namespace std;
int
main ()
{
  deque < pair < int, int >>d;
  deque < pair < int, int >>buff;
  int n, buffer;
  cin >> buffer;
  cin >> n;
  int ai[n], pi[n];
  for (int i = 0; i < n; i++)
    {
      cin >> ai[i] >> pi[i];
      d.push_back (make_pair (ai[i], pi[i]));
    }

  while (!d.empty())
    {
      if (buff.empty ())
	{
	  buff.push_front (make_pair(d.front ().first,
			  d.front ().first + d.front ().second));
	  d.pop_front ();
	}
      else
	{
	  while (d.front ().first >= buff.front ().second && !buff.empty())
	    {
	      cout << buff.front().first << endl;
	      buff.pop_front ();
	    
	    }
	if (buff.empty ())
	  {
	    buff.push_back (make_pair(d.front ().first,
			    d.front ().first + d.front ().second));
	    d.pop_front ();
	  }
	else if (buff.size () == buffer)
	  {
int e=buff.back().second;
            while(!buff.empty())
    {
        cout<<buff.front().first<<endl;
        buff.pop_front();
    }
while (d.front ().first < e && !d.empty())
	    {
	       cout << -1 << endl;
	    d.pop_front ();
	    
	    }
	  }
	else
	  {
	    int c = buff.back ().second;
	    buff.push_back (make_pair(c, c + d.front ().second));
	    d.pop_front ();
	  }

	}

    }

    while(!buff.empty())
    {
        cout<<buff.front().first<<endl;
        buff.pop_front();
    }
return 0;
}

