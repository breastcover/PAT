#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <cmath>
using namespace std;



long long to_decimal(string s,long long t)
{
  long long tmp=0;
  for(int i=0;i<s.size();i++)
  {
    if(isdigit(s[i]))
    tmp=tmp*t+(s[i]-'0');
    else
    tmp=tmp*t+(s[i]-'a'+10);
  }
  return tmp;
}



long long binary(string s,long long num)
{
  int maxx=0;;
  int t;
  long long res=-1;
  for(int i=0;i<s.size();i++)
  {
    if(isdigit(s[i]))
      t=s[i]-'0';
    else
      t=s[i]-'a'+10;
    if(t>maxx)
      maxx=t;
  }
  long long left=maxx+1,right,mid;
  right=max(num,left);
  while(left<=right)
  {
    mid=(left+right)/2;
    long long tmp=to_decimal(s,mid);
    if(tmp<0||tmp>num)
      right=mid-1;
    else if(tmp<num)
    {
      left=mid+1;
    }
    else
    {
      res=mid;
      break;
    }
  }
  return res;
}

int main()
{
  string a,b;
  int tag;
  long long r;
  cin>>a>>b>>tag>>r;

  if(tag==2)
    swap(a,b);
  //cout<<to_decimal(a,t)<<endl;
  long long tmp=to_decimal(a,r);
  int res=binary(b,tmp);
  if(res!=-1)
    cout<<res<<endl;
  else
  cout<<"Impossible"<<endl;
  return 0;
}
