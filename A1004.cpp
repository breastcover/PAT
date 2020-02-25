#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
  vector<int> child;
};

int n,m;
int res[110];
Node node[110];

void levelOrder(Node n,int level,int &flag)
{

  if(n.child.size()==0)
  {
    res[level]++;
    return ;
  }
  level++;
  flag=level;
  for(int i=0;i<n.child.size();i++)
  {
    int tmp=n.child[i];
    levelOrder(node[tmp],level,flag);
  }
}

int main()
{
  cin>>n>>m;
  if(n==0)
    return 0;
  int id,num,child;
  for(int i=0;i<m;i++)
  {
    cin>>id>>num;
    for(int j=0;j<num;j++)
    {
      cin>>child;
      node[id].child.push_back(child);
    }
  }
  int ll=0;
  int k=0;
  levelOrder(node[1],ll,k);
  
  for(int i=0;i<=k;i++)
  {
    if(i==0)
      cout<<res[i];
    else
      cout<<' '<<res[i];
  }
  cout<<endl;
  return 0;
}
