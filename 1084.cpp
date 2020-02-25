#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string aspect_num(string s,int n)
{
  if(n==1)
    return s;
  string res;
  char flag=s[0];
  int count=0;
  for(int i=0;i<=s.size();i++)
  {
    if(s[i]==flag)
      count++;
    else
    {
      res+=flag;
      res+=to_string(count);
      count=1;
      flag=s[i];
    }
  }
  s=res;
  return aspect_num(s,n-1);
}

int main()
{
  string s;
  int n;
  cin>>s>>n;
  string res;
  res=aspect_num(s,n);

  cout<<res<<endl;
  return 0;
}
