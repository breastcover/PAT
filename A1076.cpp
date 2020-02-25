#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,l;
vector<int> vec[1010];
vector<bool> vis(1010);
int lv[1010];

int bfs(int n,int level)
{
  queue<int> q;
  q.push(n);
  vis[n]=true;
  int res=0;
  lv[n]=0;
  while(!q.empty())
  {
    int tmp=q.front();
    q.pop();
    //cout<<tmp<<' '<<lv[tmp]<<' '<<vec[tmp].size()<<endl;
    for(int i=0;i<vec[tmp].size();i++)
    {
      if(vis[vec[tmp][i]]==false)
      lv[vec[tmp][i]]=lv[tmp] + 1;
      if(vis[vec[tmp][i]]==false&&lv[vec[tmp][i]]<=l)
      {
        q.push(vec[tmp][i]);
        vis[vec[tmp][i]]=true;
        res++;
      }
    }
  }
  return res;
}

int main()
{
  cin>>n>>l;
  for(int i=1;i<=n;i++)
  {
    int tmp;
    cin>>tmp;
    for(int j=0;j<tmp;j++)
    {
      int t;
      cin>>t;
      vec[t].push_back(i);
    }
  }
  int k;
  cin>>k;
  for(int i=0;i<k;i++)
  {
    fill(vis.begin(),vis.end(),false);
    int t;
    cin>>t;
    int sum=bfs(t,0);
    cout<<sum<<endl;
  }
  return 0;
}
