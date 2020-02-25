#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> vec;

int bisearch(int left,int right,int t)
{
  int mid;
  while(left<=right)
  {
    mid=(left+right)/2;
    if(vec[mid]>t)
    {
      right=mid-1;
    }
    else if(vec[mid]<t)
    {
      left=mid+1;
    }
    else if(vec[mid]==t)
      return mid;
  }
  return -1;
}

int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    vec.push_back(temp);
  }
  sort(vec.begin(),vec.end());
  int flag=0;
  for(int i=0;i<n;i++)
  {
    int v1=vec[i];
    int mid=bisearch(i,n-1,m-vec[i]);
    if(mid!=i&&mid>0)
    {
      flag=1;
      cout<<v1<<' '<<vec[mid]<<endl;
      break;
    }
  }
  if(!flag)
    cout<<"No Solution"<<endl;
  return 0;
}
