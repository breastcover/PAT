#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int nv,ne;
  cin>>nv>>ne;
  int e[nv+1][nv+1];
  fill(e[0],e[0]+(nv+1)*(nv+1),-1);
  for(int i=0;i<ne;i++)
  {
    int a,b;
    cin>>a>>b;
    e[a][b]=e[b][a]=1;
  }
  int m;
  cin>>m;
  for(int i=0;i<m;i++)
  {
    int k,isclique=1,ismaximal=1;
    cin>>k;
    vector<int> vec(k);
    for(int j=0;j<k;j++)
    {
      cin>>vec[j];
    }
    for(int j=0;j<k;j++)
    {
      if(isclique==0) break;
      for(int l=j+1;l<k;l++)
      {
        if(e[vec[j]][vec[l]]==-1)
        {
          isclique=0;
          cout<<"Not a Clique"<<endl;
          break;
        }
      }
    }
    if(isclique==0) continue;
    for(int j=1;j<=nv;j++)
    {
      if(ismaximal==0) break;
      for(int l=0;l<k;l++)
      {
        if(e[j][vec[l]]==-1)
          break;
        if(l==k-1)
        {
          cout<<"Not Maximal"<<endl;
          ismaximal=0;
        }
      }
    }
    if(ismaximal)
      cout<<"Yes"<<endl;
  }
  return 0;
}
