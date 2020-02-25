#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Symmetric(string s,int st,int longth)
{
  for(int i=st;i<longth/2+st;i++)
  {
    if(s[i]!=s[longth+st-i+st-1])
      return false;
  }
  return true;
}


int main()
{
  string s;
  getline(cin,s);
  int MAX=1;

  for(int i=0;i<s.size();i++)
  {
    for(int j=1;j<=s.size()-i;j++)
    {
      if(Symmetric(s,i,j)&&j>MAX)
      {
        MAX=j;
      }
    }
  }
  cout<<MAX<<endl;
  return 0;
}
