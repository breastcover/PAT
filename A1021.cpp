#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=10010;
vector<int> vec[10010];
int _max=0;
bool vis[10010];
int h[10010];

void dfs(int n,int h)
{
  _max=max(h,_max);
  vis[n]=true;

  for(int i=0;i<vec[n].size();i++)
  {
    int tmp=vec[n][i];
    if(!vis[tmp])
    dfs(vec[n][i],h+1);
  }
}

int main()
{
  int n;
  cin>>n;
  fill(vis,vis+MAX,false);
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  int count=0;
  for(int i=1;i<=n;i++)
  {
    if(vis[i]==false)
    {
      _max=0;
      dfs(i,1);
      h[i]=_max;
      count++;
    }
  }
  if(count>1)
    {
      cout<<"Error: "<<count<<" components"<<endl;
      return 0;
    }
  else
  {
    for(int i=1;i<=n;i++)
    {
      if(vis[i]==false)
      {
        _max=0;
        dfs(i,1);
        h[i]=_max;
        count++;
      }
      fill(vis,vis+MAX,false);
    }
    for(int i=1;i<=n;i++)
    {
      if(_max<h[i])
        _max=h[i];
    }
    for(int i=1;i<=n;i++)
    {
      //cout<<'h'<<i<<' '<<h[i]<<endl;
      if(_max==h[i])
        cout<<i<<endl;
    }
  }
  return 0;
}
