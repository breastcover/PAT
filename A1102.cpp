#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  node* lchild;
  node* rchild;
}Node;

void _invert(node* root)
{
  if(root==NULL)
    return ;
  node* tmp=root->lchild;
  root->lchild=root->rchild;
  root->rchild=tmp;
  _invert(root->lchild);
  _invert(root->rchild);
}

vector<int> in;

void in_order(node* root)
{
  if(root==NULL)
    return ;
  in_order(root->lchild);
  in.push_back(root->data);
  in_order(root->rchild);
}

vector<int> level;

void level_order(node* root)
{
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node* tmp=q.front();
    q.pop();
    level.push_back(tmp->data);
    if(tmp->lchild!=NULL)
      q.push(tmp->lchild);
    if(tmp->rchild!=NULL)
      q.push(tmp->rchild);
  }
  return ;
}

int main()
{
  int n;
  cin>>n;
  vector<bool> haveparent(n,false);
  vector<node> vec(n);
  for(int i=0;i<n;i++)
  {
    char l,r;
    cin>>l>>r;
    vec[i].data=i;
    if(isdigit(l))
    {
      vec[i].lchild=&vec[l-'0'];
      haveparent[l-'0']=true;
    }
    if(isdigit(r))
    {
      vec[i].rchild=&vec[r-'0'];
      haveparent[r-'0']=true;
    }
  }
  int root=0;
  for(int i=0;i<n;i++)
  {
    if(haveparent[i]==false)
    {
      root=i;
      break;
    }
  }

  _invert(&vec[root]);

  level_order(&vec[root]);

  in_order(&vec[root]);

  for(int i=0;i<level.size();i++)
  {
    if(i==0)
      cout<<level[i];
    else
      cout<<' '<<level[i];
  }
  cout<<endl;
  for(int i=0;i<in.size();i++)
  {
    if(i==0)
      cout<<in[i];
    else
      cout<<' '<<in[i];
  }
  cout<<endl;
  return 0;
}
