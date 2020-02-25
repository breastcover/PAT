#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string func(string s)
{
  string res;
  char c=s[0];
  int index=0,sum=0;
  while(index<=s.size())
  {
    if(s[index]==c)
    {
      sum++;
    }
    else
    {
      res+=c;
      res+=to_string(sum);
      c=s[index];
      sum=1;
    }
    index++;
  }
  return res;
}

int main()
{
  string s;
  string res=s;
  int n;
  cin>>s>>n;
  if(n==1)
  {
    cout<<s<<endl;
    return 0;
  }
  for(int i=0;i<n-1;i++)
  {
    res=func(s);
    s=res;
  }
  cout<<s<<endl;
  return 0;
}
