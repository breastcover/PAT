#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s,res;
int isOk[128];

void isStucked(string &s)
{
  for(int i=0;i<s.size();)
  {
    bool flag=0;
    for(int j=i;j<i+n;j++)
    {
      if(s[j]!=s[i])
      {
        flag=1;
        break;
      }
    }
    if(flag)
    {
      if(isOk[s[i]-'0']==-1)
        isOk[s[i]-'0']=1;
      i++;
    }
    else
    {
      if(isOk[s[i]-'0']==-1)
        isOk[s[i]-'0']=2;
      //cout<<s[i]<<' '<<isOk[s[i]-'0']<<endl;
      if(isOk[s[i]-'0']==2&&res.find(s[i])==-1)
        res+=s[i];
      if(isOk[s[i]-'0']==2)
        for(int j=1;j<n;j++)
        s.erase(s.begin()+i,s.begin()+i+1);
      else
        i++;
    }
  }
}

int main()
{
  cin>>n>>s;
  fill(isOk,isOk+128,-1);
  //for(int i=0;i<s.size();i++)
  {
    isStucked(s);
  }
  // for(int i=0;i<128;i++)
  // {
  //   cout<<(char)(i+'0')<<' '<<isOk[i]<<endl;
  // }
  cout<<res<<endl;
  cout<<s<<endl;
}
