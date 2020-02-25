#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

char c[13]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};

string encryption(string s1,string s2)
{

  if(s2.size()<s1.size())
  {
    int k=s1.size()-s2.size();
    for(int i=0;i<k;i++)
    {
      s2="0"+s2;

    }

  }


  reverse(s1.begin(),s1.end());
  reverse(s2.begin(),s2.end());
  string res;
  int i,j;
  for(i=0,j=0;i<s1.size()&&j<s2.size();i++,j++)
  {
    if(i%2==0)
      res+=c[(s1[i]-'0'+(s2[i]-'0'))%13];
    else
    {
      int k=s2[i]-'0'-(s1[i]-'0');
      if(k<0)
       k+=10;
       res=res+to_string(k);
    }
  }
  if(j<s2.size())
    res=res+s2.substr(j);
  reverse(res.begin(),res.end());
  return res;
}

int main()
{
  string s1,s2;
  cin>>s1>>s2;
  cout<<encryption(s1,s2)<<endl;
  return 0;
}
