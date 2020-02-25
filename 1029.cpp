#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string badKeybord(string s1,string s2)
{
  string s;

  for(int i=0;i<s1.size();i++)
  {
    tolower(s1[i]);
    if(s2.find(s1[i])==-1)
    {

      s1[i]=toupper(s1[i]);
      if(s.find(s1[i])==-1)
        s+=s1[i];
    }
  }
  return s;
}

int main()
{
  string input,output;
  cin>>input>>output;
  string res=badKeybord(input,output);
  cout<<res<<endl;
  return 0;
}
