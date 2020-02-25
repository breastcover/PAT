#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  int heigth;
  node* lchild;
  node* rchild;
};

node* newNode(int data)
{
  node* root=new node;
  root->data=data;
  root->lchild=root->rchild=NULL;
  root->heigth=1;
  return root;
}

int getHeight(node* root)
{
  if(root==NULL)
    return 0;
  return root->heigth;
}

int getBalanceFactor(node* root)
{
  return getHeight(root->lchild)-getHeight(root->rchild);
}

void updataHeigth(node* root)
{
  root->heigth=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

void L(node* &root)
{
  node* tmp=root->rchild;
  root->rchild=tmp->lchild;
  tmp->lchild=root;
  updataHeigth(root);
  updataHeigth(tmp);
  root=tmp;
}

void R(node* &root)
{
  node* tmp=root->lchild;
  root->lchild=tmp->rchild;
  tmp->rchild=root;
  updataHeigth(root);
  updataHeigth(tmp);
  root=tmp;
}

void insert(node* &root,int data)
{
  if(root==NULL)
  {
    root=newNode(data);
    return ;
  }
  if(data<root->data)
  {
    insert(root->lchild,data);
    updataHeigth(root);
    if(getBalanceFactor(root)==2)
    {
      if(getBalanceFactor(root->lchild)==1)
      {
        R(root);
      }else if(getBalanceFactor(root->lchild)==-1)
      {
        L(root->lchild);
        R(root);
      }
    }
  }else
  {
    insert(root->rchild,data);
    updataHeigth(root);
    if(getBalanceFactor(root)==-2)
    {
      if(getBalanceFactor(root->rchild)==-1)
      {
        L(root);
      }
      else if(getBalanceFactor(root->rchild)==1)
      {
        R(root->rchild);
        L(root);
      }
    }
  }
}

vector<int> in;
bool isComplete=true;
void levelorder(node* root)
{
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node* tmp=q.front();
    in.push_back(tmp->data);
    q.pop();
    if(tmp->lchild)
      q.push(tmp->lchild);
    if(tmp->rchild)
      q.push(tmp->rchild);
  }
}

int id=1;
void dfs(node* root,int i)
{
  if(root==NULL)
    return ;
  if(i>id)
    id=i;
  dfs(root->lchild,i*2);
  dfs(root->rchild,i*2+1);
}

int main()
{
  int n;
  cin>>n;
  node* root=NULL;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    insert(root,tmp);
  }

  levelorder(root);

  for(int i=0;i<in.size();i++)
  {
    if(i==0)
      cout<<in[i];
    else
      cout<<' '<<in[i];
  }
  cout<<endl;
  dfs(root,1);
  if(id==n)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}
