#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string _product(string s)
{
  int carry=0;
  string res;
  for(int i=s.size()-1;i>=0;i--)
  {
    int tmp=(s[i]-'0')*2+carry;
    carry=0;
    if(tmp>=10)
    {
      carry=tmp/10;
      tmp%=10;
    }
    res+=to_string(tmp);
  }
  if(carry)
    res+=to_string(carry);
  reverse(res.begin(),res.end());
  return res;
}



int main()
{
  string s;
  cin>>s;
  string res=_product(s);
  string tmp=res;
  sort(s.begin(),s.end());
  sort(tmp.begin(),tmp.end());
  if(tmp==s)
  {
    cout<<"Yes"<<endl;

  }
  else
  cout<<"No"<<endl;
  cout<<res<<endl;
  return 0;
}
