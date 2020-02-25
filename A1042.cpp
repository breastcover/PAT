#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  string s[55];
  for(int i=1;i<=54;i++)
  {
    string tmp;
    if(i<=13)
    {
      tmp="S"+to_string(i);
    }
    else if(i<=26)
    {
      tmp="H"+to_string(i-13);
    }
    else if(i<=39)
    {
      tmp="C"+to_string(i-26);
    }
    else if(i<=52)
    {
      tmp="D"+to_string(i-39);
    }
    else
    {
      tmp="J"+to_string(i-52);
    }
    s[i]=tmp;
  }
  
  int n;
  cin>>n;
  int _swap[55];
  for(int i=1;i<=54;i++)
  {
    cin>>_swap[i];
  }
  string help[55];
  while(n--)
  {
    for(int i=1;i<=54;i++)
    {
      help[_swap[i]]=s[i];
    }
    copy(help+1,help+55,s+1);
  }
  for(int i=1;i<=54;i++)
  {
    if(i==1)
      cout<<s[i];
    else
      cout<<' '<<s[i];
  }
  return 0;
}
