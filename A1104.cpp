#include <iostream>
#include <vector>
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
  double sum=0;
  for(int i=0;i<n;i++)
  {
    sum+=(double)(n-i)*vec[i]*(i+1);
  }
  printf("%.2f\n",sum);
  return 0;
}
