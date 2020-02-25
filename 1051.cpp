#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

const double eps=1e-8;

void fstimes(double a,double b,double c,double d)
{
  string s;
  double resa=a*cos(b)*c*cos(d)+a*sin(b)*(-1)*c*sin(d);
  double resb=a*cos(b)*c*sin(d)+c*cos(d)*a*sin(b);
  if(resa<eps)
    resa=0;
  if(resb<eps)
    resb=0;
  if(resb<0)
    printf("%.2lf%.2lfi",resa,resb);
  else
    printf("%.2lf+%.2lfi",resa,resb);
}

int main()
{
  double a,b,c,d;
  cin>>a>>b>>c>>d;
  fstimes(a,b,c,d);

  return 0;
}
