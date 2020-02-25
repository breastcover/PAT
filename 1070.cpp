#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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
  for(int i=0;i<n;i++)
  {
    if(i>=1)
    {
      vec[i]=(vec[i]+vec[i-1])/2;
    }
  }
  cout<<floor(vec[n-1])<<endl;
  return 0;
}
