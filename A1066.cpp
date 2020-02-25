#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
  int v,height;
  node *lchild,*rchild;
};


int getHeight(node* root)
{
  if(root==NULL)
    return 0;
  return root->height;
}

void updateHeight(node* root)
{
  root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

void L(node* &root)
{
  node* temp=root->rchild;
  root->rchild=temp->lchild;
  temp->lchild=root;
  updateHeight(root);
  updateHeight(temp);
  root=temp;
}

void R(node* &root)
{
  node* temp=root->lchild;
  root->lchild=temp->rchild;
  temp->rchild=root;
  updateHeight(root);
  updateHeight(temp);
  root=temp;
}

node* newNode(int v)
{
  node* Node=new node;
  Node->v=v;
  Node->height=1;
  Node->lchild=Node->rchild=NULL;
  return Node;
}



int getBalanceFactor(node* root)
{
  return getHeight(root->lchild)-getHeight(root->rchild);
}

void insert(node* &root,int v)
{
  if(root==NULL)
  {
    root=newNode(v);
    return ;
  }
  if(v<root->v)
  {
    insert(root->lchild,v);
    updateHeight(root);
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
  }
  else
  {
    insert(root->rchild,v);
    updateHeight(root);
    if(getBalanceFactor(root)==-2)
    {
      if(getBalanceFactor(root->rchild)==-1)
      {
        L(root);
      }else if(getBalanceFactor(root->rchild)==1)
      {
        R(root->rchild);
        L(root);
      }
    }
  }
}

node* Create(vector<int> vec)
{
  node* root=NULL;
  for(int i=0;i<vec.size();i++)
    insert(root,vec[i]);
  return root;
}

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  node* root=Create(vec);
  cout<<root->v<<endl;
  return 0;
}
