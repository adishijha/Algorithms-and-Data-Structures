#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string text;
    getline(std::cin, text);

    stack <char> s;
int start=-1;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
if(start==-1)
{

start=position;
}
s.push(next);

            
        }

        else if (next == ')' || next == ']' || next == '}') {
if(s.empty())
{
cout<<(position+1)<<endl;
return 0;
}
else
{
if((next == ')' && s.top()=='(')||(next == ']' && s.top()=='[')||(next == '}' && s.top()=='{'))
{
s.pop();
}
else
{
cout<<(position+1)<<endl;
return 0;
}
if(s.empty())
{
start=-1;
}
            
        }}
else
{
continue;

}
    }
if(s.empty())
{
cout<<"Success\n";
}
else
{
cout<<(start+1)<<endl;
}

    // Printing answer, write your code here

    return 0;
}
