#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  int G[n+1][n+1];
  bool vis[n+1];
    fill(vis,vis+n+1,false);
  fill(G[0],G[0]+((n+1)*(n+1)),-1);
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    G[a][b]=1;
    G[b][a]=1;
  }
  // for(int i=1;i<=n;i++)
  // {
  //   for(int j=1;j<=n;j++)
  //   {
  //     printf("% 2d ",G[i][j]);
  //   }
  //   cout<<endl;
  // }
  int k;
  cin>>k;
  for(int i=0;i<k;i++)
  {
    bool flag=true;
    int vertex_num,pre;
    cin>>vertex_num;
    cin>>pre;
    for(int j=1;j<vertex_num;j++)
    {
      int next;
      cin>>next;
      if(G[pre][next]==1&&!vis[next])
      {
        vis[next]=true;
        pre=next;
        continue;
      }
      else
      {
        flag=false;
        pre=next;
      }
    }
    if(flag==false||vertex_num!=n+1)
      cout<<"NO"<<endl;
    else
      cout<<"YES"<<endl;
    fill(vis,vis+n+1,false);
  }
  return 0;
}
