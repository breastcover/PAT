#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  string s;
  getline(cin,s);
  transform(s.begin(),s.end(),s.begin(),::tolower);
  //  cout<<s<<endl;
  map<string,int> mmp;
  string tmp;
  int MAX=0;
  s+=' ';
  for(int i=0;i<s.size();i++)
  {
    if(isalpha(s[i])||isdigit(s[i]))
      tmp+=s[i];
    else if(!isalpha(s[i])||!isdigit(s[i]))
    {
      //cout<<tmp<<endl;
      if(tmp!="")
      {  mmp[tmp]++;
        if(mmp[tmp]>MAX)
          MAX=mmp[tmp];
      }
      tmp="";
    }
  }
  for(auto e:mmp)
  {
    if(e.second==MAX)
    {
      cout<<e.first<<' '<<e.second;
      break;
    }
  }
  return 0;
}
