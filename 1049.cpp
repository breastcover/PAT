#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<double> vec;
  for(int i=0;i<n;i++)
  {
    double tmp;
    cin>>tmp;
    vec.push_back(tmp);
  }
  double sum=0;
  for(int i=0;i<n;i++)
  {
    sum+=(double)(n-i)*(double)(i+1)*vec[i];
  }
  printf("%.2lf\n",sum);
  return 0;
}
