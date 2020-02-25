#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int c1,c2;
  cin>>c1>>c2;
  double help=(double)(c2-c1)/100;

  int h,m,s;
  h=help/3600;
  m=(int)help%3600/60;
  s=(int)round(help)%60;
  printf("%02d:%02d:%02d\n",h,m,s);
  return 0;
}
