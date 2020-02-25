#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> zhongwen={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
vector<string> dangwei={"","Shi","Bai","Qian","Wan"};

int main()
{
  string res;
  string s;
  cin>>s;
  if(s=="0")
  {
    cout<<zhongwen[0]<<endl;
    return 0;
  }
  while(s[0]=='0')
    s.erase(s.begin());
  if(s[0]=='-')
  {
    res+="Fu ";
    s.erase(s.begin());
  }

  if(s.size()>8)
  {
    res+=(zhongwen[s[0]-'0']+' '+"Yi");
    s.erase(s.begin());
  }
  if(s.size()>4)
  {
    string temp=s.substr(0,s.size()-4);
    int t=temp.size()-1;
    while(temp[t]=='0')
      temp[t--]='*';
    int flag=1;
    while(temp!="")
    {
      if(temp[0]!='*')
      {
        if(temp[0]=='0')
        {
          if(flag)
          res+=(' '+zhongwen[temp[0]-'0']);
          flag=0;
        }
        else
        res+=(' '+zhongwen[temp[0]-'0']);
      }
      if(temp[0]!='0'&&temp[0]!='*'&&temp.size()!=1)
        res+=(' '+dangwei[temp.size()-1]);
      temp.erase(temp.begin());
    }
    if(t!=-1)
    res+=" Wan";
    else
      res+=" ling";
  }
  string temp;
  if(s.size()>=4)
    temp=s.substr(s.size()-4,s.size());
  else
    temp=s;
  int t=temp.size()-1;
  while(temp[t]=='0')
    temp[t--]='*';
  int flag=1;
  while(temp!="")
  {
    if(temp[0]!='*')
    {
      if(temp[0]=='0')
      {
        if(flag)
        res+=(' '+zhongwen[temp[0]-'0']);
        flag=0;
      }
      else
      res+=(' '+zhongwen[temp[0]-'0']);
    }
    if(temp[0]!='0'&&temp[0]!='*'&&temp.size()!=1)
      res+=(' '+dangwei[temp.size()-1]);
    temp.erase(temp.begin());
  }
  if(res[0]==' ')
    res.erase(res.begin());
  cout<<res<<endl;
  return 0;
}
