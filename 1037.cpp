#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int _toKnut(int g,int s,int a)
{
  return (17*g+s)*29+a;
}

int main()
{
  int pg,ps,pa;
  int ag,as,aa;
  int flag=0;
  scanf("%d.%d.%d %d.%d.%d",&pg,&ps,&pa,&ag,&as,&aa);
  int _pa=_toKnut(pg,ps,pa);
  int _aa=_toKnut(ag,as,aa);
  int tmp=_aa-_pa;
  if(tmp<0)
  tmp=abs(tmp),
  flag=1;
  int rg=tmp/29/17;
  int rs=(tmp-rg*17*29)/29;
  int ra=(tmp-rg*17*29-rs*29);
  if(flag)
  cout<<'-';
  cout<<rg<<'.'<<rs<<'.'<<ra<<endl;
  return 0;
}
