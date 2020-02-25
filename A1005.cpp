#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string Digit[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};


int main()
{
  string s;
  cin>>s;
  int sum=0;
  for(int i=0;i<s.size();i++)
  {
    sum+=(s[i]-'0');
  }
  string res;
  while(sum)
  {
    int tmp=sum%10;
    res=Digit[tmp]+" "+res;
    sum/=10;
  }
  if(res.size()>0)
  {
    res.erase(res.end()-1,res.end());
    cout<<res<<endl;
  }else
    cout<<"zero"<<endl;
  return 0;
}
