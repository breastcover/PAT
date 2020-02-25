
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n,m;
  cin>>n;
  vector<int> v1(n);
  for(int i=0;i<n;i++)
    scanf("%d",&v1[i]);
  cin>>m;
  int mid=(n+m+1)/2;
  int index=0;
  int res;
  for(int i=0;i<m;i++)
  {
    int tmp;
    scanf("%d",&tmp);
    while(mid&&tmp>=v1[index]&&index<n)
    {
      mid--;
      index++;
    }
    if(mid==0)
    {
      res=v1[--index];
      break;
    }
    mid--;
    if(mid==0)
    {
      res=tmp;
      break;
    }
  }
  if(mid)
  {
    while(mid--)
    {
      index++;
    }
    res=v1[--index];
  }
  cout<<res<<endl;
  return 0;
}
