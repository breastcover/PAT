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
  int m;
  cin>>m;
  vector<int> vec(100000,0);
  int n,s;
  for(int i=0;i<m;i++)
  {
    cin>>n>>s;
    vec[n]+=s;
  
  }
  int maxn=0,maxs=0;
  for(int i=0;i<100000;i++)
  {
    if(vec[i]>maxs)
    {
      maxs=vec[i];
      maxn=i;
    }
  }
  cout<<maxn<<' '<<maxs<<endl;
  return 0;
}
