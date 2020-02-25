#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
  int weight;
  vector<int> child;
}node[110];

bool cmp(int a,int b)
{
  return node[a].weight>node[b].weight;
}
int n,m,s;
vector<int> path;

void DFS(int root,int sum)
{
  if(sum>s) return ;
  if(sum==s)
  {
    if(node[root].child.size()!=0)
    return ;
    for(int i=0;i<path.size();i++)
    {
      if(i==0)
      cout<<node[path[i]].weight;
      else
      cout<<' '<<node[path[i]].weight;
    }
    cout<<endl;

    return ;
  }
  for(int i=0;i<node[root].child.size();i++)
  {
    int child=node[root].child[i];
    path.push_back(child);
    DFS(child,sum+node[child].weight);
    path.pop_back();
  }
}

int main()
{
  cin>>n>>m>>s;
  for(int i=0;i<n;i++)
    cin>>node[i].weight;
  for(int i=0;i<m;i++)
  {
    int num,children,child;
    cin>>num>>children;
    for(int j=0;j<children;j++)
    {
      cin>>child;
      node[num].child.push_back(child);
    }
    sort(node[num].child.begin(),node[num].child.end(),cmp);
  }
  path.push_back(0);
  DFS(0,node[0].weight);
  return 0;
}
