#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string to_save(string s,int n)
{
  int e;
  while(s[0]=='0'&&s.size()>0)
    s.erase(s.begin());
  string res="0.";
  if(s[0]=='.')
  {
    e=0;
    s.erase(s.begin());
    while(s[0]=='0'&&s.size()>0)
    {
      s.erase(s.begin());
      e--;
    }
    if(s.size()==0)
      e=0;
    for(int i=0;i<n&&i<s.size();i++)
    {
      res+=s[i];
    }
  }
  else
  {
    e=0;
    while(s.size()>0&&s[0]!='.')
    {
      if(res.size()<n+2)
      res+=s[0];
      s.erase(s.begin());
      e++;
    }
    if(s.size()>0)
    s.erase(s.begin());
    while(res.size()<n+2&&s.size()>0)
    {
      res+=s[0];
      s.erase(s.begin());
    }
  }


  if(res.size()<n+2)
    res.insert(res.end(),n+2-res.size(),'0');

  res=res+"*10^"+to_string(e);

  return res;
}

int main()
{
  int n;
  string a,b;
  cin>>n;
  cin>>a>>b;
  string s1=to_save(a,n);
  string s2=to_save(b,n);
  if(s1==s2)
    cout<<"YES"<<" "<<s1<<endl;
  else
    cout<<"NO"<<" "<<s1<<" "<<s2<<endl;
  return 0;
}
