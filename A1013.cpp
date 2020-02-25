#include <iostream>
#include <algorithm>
using namespace std;

int path[1001][1001];
bool vis[1001];
int n,m,k;

void dfs(int x)
{
  vis[x]=true;
  for(int i=1;i<=n;i++)
  {
    if(vis[i]==false&&path[x][i])
      dfs(i);
  }
}

int main()
{
  cin>>n>>m>>k;
  fill(path[0],path[0]+1001*1001,0);
  fill(vis,vis+1001,false);
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    path[x][y]=path[y][x]=1;
  }
  for(int i=0;i<k;i++)
  {
    int tmp;
    cin>>tmp;
    vis[tmp]=true;
    int count=0;
    for(int j=1;j<=n;j++)
    {
      if(vis[j]==false)
      {
        count++;
        dfs(j);
      }

    }
    cout<<count-1<<endl;
    fill(vis,vis+1001,false);
  }
  return 0;
}
