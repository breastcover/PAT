#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
  return a>b;
}

int main()
{
  int n,m;
  cin>>n;
  vector<int> coupons(n);
  for(int i=0;i<n;i++)
  {
    cin>>coupons[i];
  }
  cin>>m;
  vector<int> value(m);
  for(int i=0;i<m;i++)
    cin>>value[i];
  sort(coupons.begin(),coupons.end(),cmp);
  sort(value.begin(),value.end(),cmp);
  int sum=0;
  for(int i=0;i<n&&i<m;i++)
  {
    if(coupons[i]>0&&value[i]>0)
      sum+=coupons[i]*value[i];
    else
      break;
  }
  for(int i=coupons.size()-1,j=value.size()-1;i>=0&&j>=0;i--,j--)
  {
    if(coupons[i]<0&&value[j]<0)
    {
      sum+=coupons[i]*value[j];
    }
    else
      break;
  }
  cout<<sum<<endl;
  return 0;
}
