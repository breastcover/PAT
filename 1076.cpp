#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

string right_opt(string s)
{
  if(s.find("A-T")!=-1)
    return "1";
  else if(s.find("B-T")!=-1)
    return "2";
  else if(s.find("C-T")!=-1)
    return "3";
  else if(s.find("D-T")!=-1)
    return "4";
}

int main()
{
  int n;
  cin>>n;
  getchar();
  string res;
  for(int i=0;i<n;i++)
  {
    string s;
    getline(cin,s);
    res+=right_opt(s);
  }
  cout<<res<<endl;
  return 0;
}
