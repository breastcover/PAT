#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=100010;
int n,m;
vector<int> sum(MAX,0);

void bisearch(int i,int &j,int &tmpsum)
{
  int left=i,right=n;
  while(left<right)
  {
    int mid=(left+right)/2;
    if(sum[mid]-sum[i-1]>=m)
    {
      right=mid;
    }
    else
    {
      left=mid+1;
    }
  }
  j=right;

  tmpsum=sum[j]-sum[i-1];
}


int main()
{
  cin>>n>>m;
  vector<int> res;
  for(int i=1;i<=n;i++)
  {
    cin>>sum[i];
    sum[i]+=sum[i-1];
  }

  int tmpmax=sum[n];
  for(int i=1;i<=n;i++)
  {
    int j=0,tmpsum=0;
    bisearch(i,j,tmpsum);

    if(tmpsum>tmpmax)
      continue;
    //cout<<'-'<<tmpmax<<'-'<<tmpsum<<endl;
    if(tmpsum>=m)
    {
      if(tmpsum<tmpmax)
      {
        tmpmax=tmpsum;
        res.clear();
      }
      res.push_back(i);
      //cout<<i<<endl;
      res.push_back(j);
    }
  }
  //cout<<res.size()<<endl;
  for(int i=0;i<res.size();i+=2)
  {
    cout<<res[i]<<'-'<<res[i+1]<<endl;
  }
  return 0;
}
