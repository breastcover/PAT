#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<double> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end());
  double sum=0;
  for(int i=1;i<n;i++)
  {
    vec[i]=(vec[i]+vec[i-1])/2;
  }
  printf("%.f\n",floor(vec[n-1]));
  return 0;
}
