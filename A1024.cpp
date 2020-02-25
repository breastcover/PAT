#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool _ispalindromic(string s)
{

  string s2(s.rbegin(),s.rend());
  if(s==s2)
    return true;
  return false;
}

string to_palindromic(string s)
{

  string s2(s.rbegin(),s.rend());
  return s2;
}

string str_add(string s1,string s2)
{
  int carry=0;
  string res;
  for(int i=s1.size()-1;i>=0;i--)
  {
    int tmp=(s1[i]-'0')+(s2[i]-'0')+carry;
    carry=0;
    if(tmp>9)
    {
      carry=tmp/10;
      tmp%=10;
    }
    res=to_string(tmp)+res;
  }
  if(carry)
    res="1"+res;
  return res;
}


int main()
{
  string n;
  int k;
  cin>>n>>k;
  string s=n;

  for(int i=0;i<k;i++)
  {
    if(_ispalindromic(s))
    {
      cout<<s<<endl;
      cout<<i<<endl;
      break;
    }
    s=str_add(s,to_palindromic(s));
    if(i==k-1)
    {
      cout<<s<<endl;
      cout<<k<<endl;
    }
  }
  return 0;
}
