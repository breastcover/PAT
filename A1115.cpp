#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
  int data,heigth;
  node* lchild;
  node* rchild;
};

int n;
int max_level=-1;
vector<int> level(1001,0);
vector<int> vec(1001);

node* newNode(int x)
{
  node* root=new node;
  root->data=x;
  root->heigth=1;
  root->lchild=root->rchild=NULL;
  return root;
};

int getheight(node* root)
{
  if(root==NULL)
    return 0;
  return root->heigth;
}

void updataheight(node* &root)
{
  root->heigth=max(getheight(root->lchild),getheight(root->rchild))+1;
}

void insert(node* &root,int data)
{
  if(root==NULL)
  {
    root=newNode(data);
    return ;
  }
  if(root->data<data)
  {
    insert(root->rchild,data);
  }else if(root->data>=data)
  {
    insert(root->lchild,data);
  }
  updataheight(root);
}

void dfs(node* &root,int l)
{
  if(root==NULL)
    return ;
  level[l]++;
  if(l>max_level)
    max_level=l;
  dfs(root->lchild,l+1);
  dfs(root->rchild,l+1);
}

void level_order(node* root)
{
  queue<node*> q;
  q.push(root);

  while(!q.empty())
  {
    node* tmp=q.front();
    q.pop();

    cout<<tmp->data<<' '<<tmp->heigth<<endl;;
    if(tmp->lchild!=NULL)
      q.push(tmp->lchild);
    if(tmp->rchild!=NULL)
      q.push(tmp->rchild);
  }
}


node* Create()
{
  node* root=NULL;
  for(int i=0;i<n;i++)
  {
    insert(root,vec[i]);
  }
  return root;
}

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>vec[i];
  node* root=Create();
  dfs(root,1);
  
  cout<<level[max_level]<<" + "<<level[max_level-1]<<" = "<<level[max_level]+level[max_level-1]<<endl;
  return 0;
}
