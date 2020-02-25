#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const double eps=1e-8;

int jtoy(int n)
{
  int gewei=n%10;
  int shiwei=n/10;
  return gewei*10+shiwei;
}

string print(double n,int m)
{
  if(n>m)
    return " Cong";
  else if(n<m)
    return " Gai";
  else
    return " Ping";
}

int main()
{
  int m,x,y;
  cin>>m>>x>>y;
  int jn,yn;
  double bn;
  for(jn=99;jn>=10;jn--)
  {
    yn=jtoy(jn);
    bn=(double)yn/(double)y;
    if(fabs(abs(jn-yn)-bn*x)<eps)
      break;
  }
  if(jn>=10)
  cout<<jn<<print(jn,m)<<print(yn,m)<<print(bn,m)<<endl;
  else
  cout<<"No Solution"<<endl;
  return 0;
}
