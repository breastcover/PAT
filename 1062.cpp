#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

const double eps=1e-8;

int gcd(int a,int b)
{
  if(a%b==0)
    return b;
  return gcd(b,a%b);
}

int main()
{
  int n1,m1,n2,m2,k;
  scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
  double a,b;
  a=(double)n1/m1;
  b=(double)n2/m2;
  if(a>b)
  {
    double tmp=a;
    a=b;
    b=tmp;
  }
  int i=0;
  vector<int> vec;
  while(1)
  {
    i++;
    double d=(double)i/k;
    if(gcd(i,k)==1&&d-a>eps&&b-d>eps)
    {
      vec.push_back(i);
    }
    if(d-b>eps)
      break;
  }
  for(int i=0;i<vec.size()-1;i++)
  {
    printf("%d/%d ",vec[i],k);
  }
  printf("%d/%d\n",vec[vec.size()-1],k);
  return 0;
}
