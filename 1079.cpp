#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string string_sum(string a)
{
  string b(a.rbegin(),a.rend());
  string res;
  int carry=0;
  for(int i=a.size()-1;i>=0;i--)
  {
    int tmp=a[i]-'0'+(b[i]-'0')+carry;
    res=to_string(tmp%10)+res;
    carry=tmp/10;
  }
  if(carry!=0)
  res="1"+res;
  return res;
}

bool _palindromic(string s)
{
  string tmp(s.rbegin(),s.rend());
  if(s==tmp)
    return true;
  return false;
}

int main()
{
  string s;
  cin>>s;
  if(_palindromic(s))
  {
    cout<<s<<" is a palindromic number."<<endl;
    return 0;
  }
  string res;
  for(int i=0;i<10;i++)
  {
    string tmp=s;
    string b(s.rbegin(),s.rend());
    res=string_sum(s);
    s=res;
    cout<<tmp<<" + "<<b<<" = "<<res<<endl;
    if(_palindromic(s))
    {
      cout<<s<<" is a palindromic number."<<endl;
      break;
    }
  }
  if(!_palindromic(s))
  cout<<"Not found in 10 iterations."<<endl;
  return 0;
}
