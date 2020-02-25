#include <iostream>
#include <math.h>
#include <string>
using namespace std;

long long gcd(long long a,long long b)
{
  if(b==0)
    return a;
  else
    return gcd(b,a%b);
}

long long lcd(long long a,long long b)
{
  return a*b/gcd(a,b);
}

struct frac
{
  int fh=1;
  long long fz;
  long long fm;
};


string dealFrac(frac f)
{
  if(f.fz<0&&f.fm>0||f.fm<0&&f.fz>0)
  {
    f.fh=-1;
    f.fz=abs(f.fz);
    f.fm=abs(f.fm);
  }
  int p=gcd(f.fz,f.fm);
  f.fz/=p;
  f.fm/=p;
  if(f.fz==0)
    return "0";
  string s;
  if(f.fz/f.fm>0)
  {
    s=s+to_string(f.fz/f.fm);
    if(f.fm!=1)
      s=s+' '+to_string(abs(f.fz%f.fm))+"/"+to_string(f.fm);
  }
  else
    s=to_string(f.fz)+"/"+to_string(f.fm);
  if(f.fh==-1)
  s="(-"+s+')';

  return s;
}


int main()
{
  frac f1,f2;
  scanf("%lld/%lld %lld/%lld",&f1.fz,&f1.fm,&f2.fz,&f2.fm);

  long long d1=gcd(f1.fz,f1.fm);
  f1.fz/=d1;
  f1.fm/=d1;
  long long d2=gcd(f2.fz,f2.fm);
  f2.fz/=d2;
  f2.fm/=d2;
  frac plus;

  //cout<<f1.fz<<" "<<f1.fm<<" "<<f2.fz<<" "<<f2.fm<<endl;
  plus.fh=f1.fh*f2.fh;
  plus.fz=f1.fz*f2.fm+f2.fz*f1.fm;
  plus.fm=f1.fm*f2.fm;
  
  //cout<<plus_fz<<" "<<plus_fm<<endl;
  // long long d3=gcd(plus_fm,plus_fz);
  // plus_fm/=d3;
  // plus_fz/=d3;
  frac minus;
  minus.fh=f1.fh*f2.fh;
  minus.fz=f1.fz*f2.fm-f2.fz*f1.fm;
  minus.fm=f1.fm*f2.fm;

  frac times;
  times.fz=f1.fz*f2.fz;
  times.fm=f1.fm*f2.fm;
  frac divided;
  divided.fh=f1.fh*f2.fh;
  divided.fz=f1.fz*f2.fm;
  divided.fm=f2.fz*f1.fm;

  cout<<dealFrac(f1)<<" "<<"+"<<" "<<dealFrac(f2)<<" "<<"="<<" "<<dealFrac(plus)<<endl;
  cout<<dealFrac(f1)<<" "<<"-"<<" "<<dealFrac(f2)<<" "<<"="<<" "<<dealFrac(minus)<<endl;
  cout<<dealFrac(f1)<<" "<<"*"<<" "<<dealFrac(f2)<<" "<<"="<<" "<<dealFrac(times)<<endl;
  if(divided.fm==0)
  cout<<dealFrac(f1)<<" "<<"/"<<" "<<dealFrac(f2)<<" "<<"="<<" "<<"Inf"<<endl;
  else
  cout<<dealFrac(f1)<<" "<<"/"<<" "<<dealFrac(f2)<<" "<<"="<<" "<<dealFrac(divided)<<endl;
  return 0;
}
