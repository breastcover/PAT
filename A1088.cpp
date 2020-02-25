#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}

long long lcd(long long a,long long b)
{
  return a*b/gcd(a,b);
}

void _transform(long long a,long long b)
{
  long long g=gcd(abs(a),b);
  a/=g;
  b/=g;
  //cout<<a<<b<<endl;
  long long _integer=a/b;
  if(_integer)
    a=abs(a)%b;
  if(_integer>0)
  {
    cout<<_integer;
    if(a)
      cout<<' ';
    if(a!=0)
      cout<<a<<'/'<<b;
  }
  else if(_integer<0)
  {
    cout<<'('<<_integer;
    if(a!=0)
      cout<<' '<<a<<'/'<<b;
    cout<<')';
  }
  else
  {
    if(a==0)
      cout<<_integer;
    else if(a>0)
      cout<<a<<'/'<<b;
    else
      cout<<'('<<a<<'/'<<b<<')';
  }
}

void _add(long long a1,long long b1,long long a2,long long b2)
{
  _transform(a1,b1);
  cout<<" + ";
  _transform(a2,b2);
  cout<<" = ";
  long long a;
  long long l=lcd(b1,b2);
  a1=l/b1*a1;
  a2=l/b2*a2;
  a=a1+a2;
  _transform(a,l);
  cout<<endl;
}

void _sub(long long a1,long long b1,long long a2,long long b2)
{
  _transform(a1,b1);
  cout<<" - ";
  _transform(a2,b2);
  cout<<" = ";
  long long l=lcd(b1,b2);
  long long a;
  a1=l/b1*a1;
  a2=l/b2*a2;
  a=a1-a2;
  _transform(a,l);
  cout<<endl;
}

void _mul(long long a1,long long b1,long long a2,long long b2)
{
  _transform(a1,b1);
  cout<<" * ";
  _transform(a2,b2);
  cout<<" = ";
  long long l=lcd(b1,b2);
  a1*=a2;
  b1*=b2;
  _transform(a1,b1);
  cout<<endl;
}

void _div(long long a1,long long b1,long long a2,long long b2)
{
  _transform(a1,b1);
  cout<<" / ";
  _transform(a2,b2);
  cout<<" = ";
  if(a2==0)
  {
    cout<<"Inf"<<endl;
    return ;
  }
  a1*=b2;
  b1*=a2;
  if(b1<0)
  {
    a1*=-1;
    b1*=-1;
  }
  _transform(a1,b1);
  cout<<endl;
}

int main()
{
  long long a1,b1,a2,b2;
  scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
  _add(a1,b1,a2,b2);
  _sub(a1,b1,a2,b2);
  _mul(a1,b1,a2,b2);
  _div(a1,b1,a2,b2);
  return 0;
}
