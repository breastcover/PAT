#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
  string s1,s2;
  getline(cin,s1);
  getline(cin,s2);
  
  string res="";
  for(int i=0;i<s1.size();i++)
  {
    if(res.find(s1[i])==string::npos)
      res+=s1[i];
  }
  for(int i=0;i<s2.size();i++)
  {
    if(res.find(s2[i])==string::npos)
      res+=s2[i];
  }
  cout<<res<<endl;
  return 0;
}
