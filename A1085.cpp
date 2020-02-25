#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,p;
vector<long long> vec(100010);

int bisearch(int left,int right)
{
  int _min=vec[left];
  while(left<right)
  {
    int mid=(left+right)/2;
    if(_min*p<vec[mid])
      right=mid;
    else
      left=mid+1;
  }
  return left;
}

int main()
{
  cin>>n>>p;
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
  }
  sort(vec.begin(),vec.begin()+n);
  int sum=0;
  for(int i=0;i<n;i++)
  {
    sum=max(sum,bisearch(i,n)-i);
  }
  cout<<sum<<endl;
  return 0;
}
