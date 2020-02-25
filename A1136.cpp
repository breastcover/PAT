#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindromic(string s)
{
  string rs(s.rbegin(),s.rend());
  if(rs==s)
    return true;
  return false;
}

string _sum(string s,string rs)
{
  int carry=0;
  string res;
  for(int i=s.size()-1;i>=0;i--)
  {
    int tmp=(s[i]-'0')+(rs[i]-'0')+carry;
    carry=0;
    if(tmp>=10)
    {
      tmp%=10;
      carry=1;
    }
    res=to_string(tmp)+res;
  }
  if(carry)
    res='1'+res;
  return res;
}

int main()
{
  string s;
  cin>>s;
  string res;
  if(isPalindromic(s))
  {
    cout<<s<<" is a palindromic number."<<endl;
    return 0;
  }
  for(int i=0;i<10;i++)
  {
    string rs(s.rbegin(),s.rend());
    res=_sum(s,rs);
    cout<<s<<" + "<<rs<<" = "<<res<<endl;
    if(isPalindromic(res))
    {
      cout<<res<<" is a palindromic number."<<endl;
      break;
    }
    s=res;
  }
  if(!isPalindromic(res))
  cout<<"Not found in 10 iterations."<<endl;
  return 0;
}
