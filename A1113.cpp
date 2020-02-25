#include <iostream>
#include <vector>
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
  int n1=n/2;
  int n2=n-n1;
  int s1=0,s2=0;
  for(int i=0;i<n;i++)
  {
    if(i<n1)
      s1+=vec[i];
    else
      s2+=vec[i];
  }
  cout<<n2-n1<<' '<<abs(s2-s1)<<endl;
  return 0;
}
