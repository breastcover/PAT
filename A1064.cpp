#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct node
{
  int data,height;
  node* lchild;
  node* rchild;
};

node* newNode(int v)
{
  node* Node=new node;
  Node->data=v;
  Node->height=1;
  Node->lchild=Node->rchild=NULL;
  return Node;
}

int getHeight(node* root)
{
  if(root==NULL)
    return 0;
  return root->height;
}

int getBalance(node* root)
{
  return getHeight(root->lchild)-getHeight(root->rchild);
}

void updateHeight(node* root)
{
  root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

void L(node* &root)
{
  node* tmp=root->rchild;
  root->rchild=tmp->lchild;
  tmp->lchild=root;
  updateHeight(root);
  updateHeight(tmp);
  root=tmp;
}

void R(node* &root)
{
  node* tmp=root->lchild;
  root->lchild=tmp->rchild;
  tmp->rchild=root;
  updateHeight(root);
  updateHeight(tmp);
  root=tmp;
}

void insert(node* &root,int v)
{
  if(root==NULL)
  {
    root=newNode(v);
    return ;
  }
  if(v<root->data)
  {
    insert(root->lchild,v);
    updateHeight(root);
    if(getBalance(root)==2)
    {
      if(getBalance(root->lchild)==1)
      {
        R(root);
      }else if(getBalance(root->lchild)==-1)
      {
        L(root->lchild);
        R(root);
      }
    }
  }else
  {
    insert(root->rchild,v);
    updateHeight(root);
    if(getBalance(root)==-2)
    {
      if(getBalance(root->rchild)==-1)
      {
        L(root);
      }else if(getBalance(root->rchild)==1)
      {
        R(root->rchild);
        L(root);
      }
    }
  }
}

void level_order(node* root)
{
  deque<node*> q;
  q.push_back(root);
  while(!q.empty())
  {
    node* tmp=q.front();
    cout<<tmp->data<<' ';
    if(tmp->lchild)
    q.push_back(tmp->lchild);
    if(tmp->rchild)
    q.push_back(tmp->rchild);
    q.pop_front();
  }
}

node* Create(vector<int> &vec)
{
  node* root=NULL;
  for(int i=0;i<vec.size();i++)
  {
    //cout<<i<<endl;
    insert(root,vec[i]);
  }
  return root;
}

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  //cout<<1<<endl;
  node* root=Create(vec);
  level_order(root);
  return 0;
}
