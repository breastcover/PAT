#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> vec[n];
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    vec[a].push_back(i);
    vec[b].push_back(i);
  }
  int k;
  cin>>k;
  for(int i=0;i<k;i++)
  {
    int nv;
    cin>>nv;
    vector<int> hash(m,0);
    for(int j=0;j<nv;j++)
    {
      int v;
      cin>>v;
      for(int l=0;l<vec[v].size();l++)
      {
        hash[vec[v][l]]=1;
      }
    }
    int flag=0;
    for(int j=0;j<m;j++)
    {
      if(hash[j]==0)
      {
        cout<<"No"<<endl;
        flag=1;
        break;
      }
    }
    if(!flag)
      cout<<"Yes"<<endl;
  }
  return 0;
}
