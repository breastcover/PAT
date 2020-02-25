#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
  string data;
  int lchild;
  int rchild;
};

vector<node> vec(21);

void dfs(int root,int level)
{
  if(vec[root].data=="")
    return ;
  if(vec[root].lchild==-1&&vec[root].rchild==-1)
    cout<<vec[root].data;
  else
  {
    if(level>0)
      cout<<'(';
    dfs(vec[root].lchild,level+1);
    cout<<vec[root].data;
    dfs(vec[root].rchild,level+1);
    if(level>0)
    cout<<')';
  }
}

int main()
{
  int n;
  cin>>n;
  vector<bool> haveparent(n+1,false);
  for(int i=1;i<=n;i++)
  {
    cin>>vec[i].data>>vec[i].lchild>>vec[i].rchild;
    if(vec[i].lchild!=-1)
    haveparent[vec[i].lchild]=true;
    if(vec[i].rchild!=-1)
    haveparent[vec[i].rchild]=true;
  }
  int root;
  for(int i=1;i<=n;i++)
  {
    if(haveparent[i]==false)
    {
      root=i;
    }
  }
  //cout<<vec[root].data<<endl;
  dfs(root,0);
  return 0;
}
