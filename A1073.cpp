#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
  string s,res;
  int exponent;
  cin>>s;
  if(s[0]=='-')
    res+='-';
  for(int i=1;i<s.size();i++)
  {
    if(s[i]=='E')
    {
      string tmp=s.substr(i+1,s.size());

      exponent=stoi(tmp);
    }
  }
  //cout<<exponent<<endl;
  if(exponent<0)
  {
    res+="0.";
    exponent*=-1;
    for(int i=1;i<exponent;i++)
    {
      res+='0';
    }
    for(int i=1;i<s.size();i++)
    {
      if(s[i]=='E')
        break;
      if(s[i]!='.')
      res+=s[i];
    }
  }
  else if(exponent>0)
  {
    for(int i=1;i<s.size();i++)
    {
      if(s[i]=='E')
        break;
      if(s[i]!='.')
      res+=s[i];
      if(i>2)
      {
        exponent--;
        if(exponent==0)
        res+='.';
      }
    }
    for(int i=0;i<exponent;i++)
      res+='0';
  }
  else
  {
    for(int i=1;i<s.size();i++)
    {
      if(s[i]=='E')
        break;
      res+=s[i];
    }
  }
  if(res[res.size()-1]=='.')
    res.erase(res.end()-1,res.end());
  cout<<res<<endl;
  return 0;
}
