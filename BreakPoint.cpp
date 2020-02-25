#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
  double BreakPiont=0.618;
  double min=20;
  int fm,fz;
  for(int i=1;i<=20;i++)
  {
    for(int j=1;j<=20;j++)
    {
      if(i%2==0&&j%2==0)
        continue;
      if(fabs((double)i/(double)j-BreakPiont)<min)
      {
        min=fabs((double)i/(double)j-BreakPiont);
        fm=j;
        fz=i;
        cout<<fz<<' '<<fm<<' '<<min<<endl;
      }
    }
  }
  cout<<fz<<' '<<fm<<endl;
}
