#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<n;i++)
  {
    if(vec[i]>n-i)
    {
      cout<<n-i<<endl;
      break;
    }
    if(i==n-1)
      cout<<0<<endl;
  }
  return 0;
}
