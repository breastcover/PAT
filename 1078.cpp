#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;

string Compression(string s)
{
  char flag=s[0];
  string res;
  int count=0;
  for(int i=0;i<=s.size();i++)
  {
    if(s[i]==flag)
      count++;
    else if(s[i]!=flag)
    {
      if(count>1)
      res=res+to_string(count)+flag;
      else
      res+=flag;
      flag=s[i];
      count=1;
    }
    
  }
  return res;
}

string Decompression(string s)
{
  string res;
  string tmp="0";
  for(int i=0;i<s.size();i++)
  {
    if(isdigit(s[i]))
    {
      tmp+=s[i];

    }
    else if(tmp!="0")
    {
      int count=stoi(tmp);
      string ss(count,s[i]);
      res+=ss;
      tmp="0";
    }
    else
      res+=s[i];
  }
  return res;
}

int main()
{
  char c;
  cin>>c;
  string s;
  getchar();
  getline(cin,s);
  if(c=='C')
    cout<<Compression(s)<<endl;
  else if(c=='D')
    cout<<Decompression(s)<<endl;
  return 0;
}
