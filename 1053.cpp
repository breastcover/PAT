#include <iostream>
#include <math.h>
using namespace std;

const double eps=0.05;

int main()
{
  double knkz=0,kz=0;
  int n,d;
  double e;
  cin>>n>>e>>d;
  for(int t=0;t<n;t++)
  {
    int k;
    cin>>k;
    int num=0;
    for(int i=0;i<k;i++)
    {
      double tmp;
      cin>>tmp;
      if(tmp-e<-eps)
        num++;
    }
    if(num>k/2)
    {
      if(k>d)
       kz++;
      else
        knkz++;
    }
  }

  printf("%.1lf%% %.1lf%%\n",knkz/n*100,kz/n*100);
  return 0;
}
