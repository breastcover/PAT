#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=100010;

struct node
{
  int data;
  node* lchild;
  node* rchild;
};

int n,m;
int t1,t2;
vector<int> in(MAX);
vector<int> pre(MAX);

node* CreateTree(int preL,int preR,int inL,int inR)
{
  if(preL>preR)
    return NULL;
  node* root=new node;
  root->data=pre[preL];
  int i;
  for(i=inL;i<=inR;i++)
  {
    if(in[i]==pre[preL])
      break;
  }
  int numLeft=i-inL;
  root->lchild=CreateTree(preL+1,preL+numLeft,inL,i-1);
  root->rchild=CreateTree(preL+numLeft+1,preR,i+1,inR);
  return root;
}

int dfs(node* &root)
{
  if(root==NULL)
    return -1;
  bool findKey=false;
  if(root->data==t1||root->data==t2)
    findKey=true;

  int left=dfs(root->lchild);

  int right=dfs(root->rchild);
  if(left!=-1&&right!=-1)
  {
    printf("LCA of %d and %d is %d.\n", t1, t2, root->data);
    return -1;
  }else if(findKey==true&&(left!=-1||right!=-1 ||t1==t2))
  {
    printf("%d is an ancestor of %d.\n", root->data, t1 == t2 ? t1 : left != -1 ? left : right);
        return -1;
  }else if(findKey)
  {
    return root->data;
  }else if(left!=-1||right!=-1)
  {
    return left!=-1?left:right;
  }
  return -1;
}


int main()
{
  cin>>m>>n;
  for(int i=1;i<=n;i++)
    cin>>in[i];
  for(int i=1;i<=n;i++)
    cin>>pre[i];
  node* root=CreateTree(1,n,1,n);
  node* help=root;
  for(int i=0;i<m;i++)
  {
    cin>>t1>>t2;
    bool f_t1=false,f_t2=false;
    for(int j=1;j<=n;j++)
    {
      if(in[j]==t1)
        f_t1=true;
      if(in[j]==t2)
        f_t2=true;
    }
    if(f_t1==false&&f_t2==false)
    {
      cout<<"ERROR: "<<t1<<" and "<<t2<<" are not found."<<endl;
    }else if(f_t1==false)
    {
      cout<<"ERROR: "<<t1<<" is not found."<<endl;
    }else if(!f_t2)
      cout<<"ERROR: "<<t2<<" is not found."<<endl;
    else
      dfs(root);
  }
  return 0;
}
