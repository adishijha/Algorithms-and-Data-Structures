#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
using
  std::max_element;

int
main ()
{
  stack < int >
    s;
  int
    num_queries = 0;
  cin >> num_queries;

  string
    query;
  string
    value;
  stack < int >
    max;
  max.push (-1);
  for (int i = 0; i < num_queries; ++i)
    {
      cin >> query;
      if (query == "push")
	{
	  cin >> value;
	  s.push (std::stoi (value));
	  if (stoi(value) >= max.top ())
	    {
	      max.push (stoi (value));
	    }
	}
      else if (query == "pop")
	{
	  if (!s.empty ())
	    {
	      int
		m = s.top ();
	      s.pop ();
	      if (max.top () == m)
		{

		  max.pop ();
		}
	    }
	}
      else if (query == "max")
	{
	  if (!max.empty ())
	    {
	        if(max.top()!=-1)
	        {
	      cout << max.top () << "\n";
	        }
	    }
	}
    }
  return 0;
}

