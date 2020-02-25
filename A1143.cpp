#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  node* lchild;
  node* rchild;
};

int m,n;
vector<int> pre(10010);
vector<int> in(10010);

node* newNode(int data)
{
  node* root=new node;
  root->data=data;
  root->lchild=root->rchild=NULL;
  return root;
}

node* create(int preL,int preR,int inL,int inR)
{
  if(preL>preR)
    return NULL;
  node* root=newNode(pre[preL]);
  int k;
  for(k=inL;k<=inR;k++)
  {
    if(in[k]==pre[preL])
      break;
  }
  int numLeft=k-inL;
  root->lchild=create(preL+1,preL+numLeft,inL,k-1);
  root->rchild=create(preL+numLeft+1,preR,k+1,inR);
  return root;
}

void dfs(node* root,int a,int b)
{
  if(root==NULL)
    return ;
  if(root->data==a)
  {
    printf("%d is an ancestor of %d.\n",a,b);
  }else if(root->data==b)
  {
    printf("%d is an ancestor of %d.\n",b,a);
  }else if(root->data>a&&root->data<b)
  {
    printf("LCA of %d and %d is %d.\n",a,b,root->data);
  }else if(root->data<a&&root->data>b)
  {
    printf("LCA of %d and %d is %d.\n",a,b,root->data);
  }
  if(root->data>a&&root->data>b)
    dfs(root->lchild,a,b);
  else if(root->data<b&&root->data<a)
    dfs(root->rchild,a,b);
}

int main()
{
  cin>>m>>n;
  for(int i=1;i<=n;i++)
  {
    int tmp;
    cin>>tmp;
    pre[i]=in[i]=tmp;
  }
  sort(in.begin()+1,in.begin()+n);
  node* root=create(1,n,1,n);
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    bool nfa=true,nfb=true;
    for(int j=1;j<=n;j++)
    {
      if(in[j]==a)
        nfa=false;
      if(in[j]==b)
        nfb=false;
    }
    if(nfa&&nfb)
    {
      printf("ERROR: %d and %d are not found.\n",a,b);
    }else if(nfa)
    {
      printf("ERROR: %d is not found.\n",a);
    }else if(nfb)
    {
      printf("ERROR: %d is not found.\n",b);
    }else
    {
      dfs(root,a,b);
    }
  }
  return 0;
}
