#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string _reverse(string s)
{
  string tmp(s.rbegin(),s.rend());
  return tmp;
}

int main()
{
  string s;
  cin>>s;

  while(1)
  {
    while(s.size()<4)
      s="0"+s;
    sort(s.begin(),s.end());
    string s2=_reverse(s);
    if(s==s2)
    {
      printf("%04d - %04d = 0000\n",stoi(s),stoi(s));
      return 0;
    }
    int tmp=stoi(s2)-stoi(s);
    printf("%04d - %04d = %04d\n",stoi(s2),stoi(s),tmp);
    s=to_string(tmp);
    if(tmp==6174)
      break;
  }
  return 0;
}
