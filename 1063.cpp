#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double maxn=0;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    double a,b;
    cin>>a>>b;
    double tmp=sqrt(pow(a,2)+pow(b,2));
    if(tmp>maxn)
      maxn=tmp;
  }
  printf("%.2f\n",maxn);
  return 0;
}
