#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long gcd(long long a,long long b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
};

long long lcd(long long a,long long b)
{
  return a*b/gcd(a,b);
}

int main()
{
  int n;
  cin>>n;
  long long a,b;
  scanf("%lld/%lld",&a,&b);
  for(int i=1;i<n;i++)
  {
    long long ta,tb;
    scanf("%lld/%lld",&ta,&tb);
    long long tl=lcd(b,tb);
    a=tl/b*a;
    ta=tl/tb*ta;
    a+=ta;
    b=tl;
    long long tg=gcd(abs(a),b);
    a/=tg;
    b/=tg;
  }
  long long _integer=0;
  if(a>b)
  {
    _integer=a/b;
    a%=b;
  }
  if(b!=1)
  {
    if(_integer)
      cout<<_integer<<' '<<a<<'/'<<b<<endl;
    else
      cout<<a<<'/'<<b<<endl;
  }
  else
  {
    cout<<_integer<<endl;
  }
  return 0;
}
