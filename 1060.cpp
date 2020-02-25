#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
  return a>b;
}

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
  }
  sort(vec.begin(),vec.end(),cmp);

  for(int i=n-1;i>=0;i--)
  {
    if(vec[i]>i+1)
    {
      cout<<i+1<<endl;
      break;
    }
    if(i==0)
    {
      cout<<0<<endl;
    }
  }
  return 0;
}
