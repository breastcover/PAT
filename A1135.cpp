#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct node
{
  int data;
  node* lchild;
  node* rchild;
};

int n,m;
vector<int> vec;

node* newNode(int data)
{
  node* root=new node;
  root->data=data;
  root->lchild=root->rchild=NULL;
  return root;
}

void insert(node* &root,int data)
{
  if(root==NULL)
  {
    root=newNode(data);
    return ;
  }
  if(abs(root->data)>=abs(data))
    insert(root->lchild,data);
  else if(abs(root->data)<abs(data))
    insert(root->rchild,data);
}

node* creat()
{
  node* root=NULL;
  for(int i=0;i<vec.size();i++)
  {
    insert(root,vec[i]);
  }
  return root;
}

void inorder(node* root)
{
  if(root==NULL)
    return ;
  inorder(root->lchild);
  cout<<root->data<<' ';
  inorder(root->rchild);
}

bool judge1(node* root)
{
  if(root==NULL)
    return true;
  if(root->data<0)
  {
    if(root->lchild!=NULL&&root->lchild->data<0)
      return false;
    if(root->rchild!=NULL&&root->rchild->data<0)
      return false;
  }
  return judge1(root->lchild)&&judge1(root->rchild);
}

int getNum(node* root)
{
  if(root==NULL)
    return 0;
  int l=getNum(root->lchild);
  int r=getNum(root->rchild);
  return root->data>0?max(l,r)+1:max(l,r);
}

bool judge2(node* root)
{
  if(root==NULL)
    return true;
  if(getNum(root->lchild)!=getNum(root->rchild))
    return false;
  return judge2(root->lchild)&&judge2(root->rchild);
}

int main()
{
  cin>>n;
  for(int j=0;j<n;j++)
  {
    cin>>m;
    vec.clear();
    for(int i=0;i<m;i++)
    {
      int tmp;
      cin>>tmp;
      vec.push_back(tmp);
    }
    node* root=creat();
    
    if(vec[0]<0||!judge1(root)||!judge2(root))
      cout<<"No"<<endl;
    else
      cout<<"Yes"<<endl;
  }
  return 0;
}
