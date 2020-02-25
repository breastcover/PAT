#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  string ss(s1.size()-s2.size(),'0');
  s2=ss+s2;
  string ss1(s1.size()-s3.size(),'0');
  s3=ss1+s3;
  string res;
  reverse(s1.begin(),s1.end());
  reverse(s2.begin(),s2.end());
  reverse(s3.begin(),s3.end());

  int rest=0;
  for(int i=0;i<s1.size();i++)
  {
    int tmp=(s2[i]-'0')+(s3[i]-'0')+rest;
    int jz=s1[i]-'0';
    if(jz==0)
      jz=10;
    rest=tmp/jz;
    tmp%=jz;
    res+=(tmp+'0');
  }
  if(rest!=0) res+='1';
  reverse(res.begin(),res.end());
  while(res[0]=='0'&&res.size()>1)
    res.erase(res.begin(),res.begin()+1);
  cout<<res<<endl;
  return 0;
}
