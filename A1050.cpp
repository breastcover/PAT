#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

string _sub(string s1,string s2){
  for(int i=0;i<s2.size();i++)
  {
    for(int j=0;j<s1.size();)
    {
      if(s1[j]==s2[i])
        s1.erase(s1.begin()+j,s1.begin()+j+1);
      else
        j++;
    }
  }
  return s1;
}


int main()
{
  string s1,s2;
  getline(cin,s1);
  getline(cin,s2);
  string s=_sub(s1,s2);
  cout<<s<<endl;
  return 0;
}
