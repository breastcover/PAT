#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string mars_num[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[12]={"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};

string to_mars(int n)
{
  string res;
  if(n==0)
    return "tret";
  else
  {
    if(n%13!=0)
    {
      res=mars_num[n%13]+res;
    }
    if(res.size()>0&&n>13)
      res=' '+res;
    if(n>=13)
    res=high[n/13-1]+res;
  }
  return res;
}

int to_num(string s)
{
  int n=0;
  if(s.size()==3)
  {
    for(int i=0;i<13;i++)
    {
      if(mars_num[i]==s)
        n=i;
    }
    for(int i=0;i<12;i++)
    {
      if(high[i]==s)
        n=(i+1)*13;
    }
  }
  else
  {
    string h=s.substr(0,3);
    string l=s.substr(4,7);


      for(int i=0;i<13;i++)
      {
        if(mars_num[i]==l)
            n=i;
      }
      for(int i=0;i<12;i++)
      {
        if(high[i]==h)
           n=(i+1)*13+n;
      }

  }
  return n;
}

int main()
{
  int n;
  cin>>n;
  getchar();
  for(int i=0;i<n;i++)
  {
    int num;
    string s;
    getline(cin,s);

    if(isdigit(s[0]))
    {
        num=stoi(s);
        cout<<to_mars(num)<<endl;
    }
    else
    cout<<to_num(s)<<endl;
  }
  return 0;
}
