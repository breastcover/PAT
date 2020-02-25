#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

const string _day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
  string res;
  string s1,s2;
  cin>>s1>>s2;
  int n=s1.size()>s2.size()?s2.size():s1.size();
  int t=0;
  for(int i=0;i<n;i++)
  {
    if(s1[i]==s2[i]&&(s1[i]>='A'&&s1[i]<='N'||isdigit(s1[i])))
    {
      if(t==1)
      {
        if(isdigit(s1[i]))
        {
          res=res+' '+'0'+s1[i];
        }
        else
          res=res+' '+to_string(s1[i]-'A'+10);
        break;
      }

    }
    if(s1[i]==s2[i]&&(s1[i]>='A'&&s1[i]<='G'))
    {
      if(t==0)
      {
        res+=_day[s1[i]-'A'];
        t=1;
      }
    }

  }
  cin>>s1>>s2;
  n=s1.size()>s2.size()?s2.size():s1.size();
  for(int i=0;i<n;i++)
  {
    if(s1[i]==s2[i]&&isalpha(s1[i]))
    {
      string s;
      if(i<10)
        s="0"+to_string(i);
      else
        s=to_string(i);
      res=res+':'+s;
      break;
    }
  }
  cout<<res<<endl;
  return 0;
}
