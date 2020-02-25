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

int n;
vector<int> preorder(50001);
vector<int> inorder(50001);
vector<int> postorder;

node* Create(int preL,int preR,int inL,int inR)
{
  if(preL>preR)
    return NULL;
  node* root=new node;
  root->data=preorder[preL];
  int k=0;
  for(int i=inL;i<=inR;i++)
  {
    if(inorder[i]==preorder[preL])
    {
      k=i;
      break;
    }
  }
  int Numleft=k-inL;
  root->lchild=Create(preL+1,preL+Numleft,inL,k-1);
  root->rchild=Create(preL+Numleft+1,preR,k+1,inR);
  return root;
}

void postOrder(node* root)
{
  if(root==NULL)
    return ;
  postOrder(root->lchild);
  postOrder(root->rchild);
  postorder.push_back(root->data);
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>preorder[i];
  }
  for(int i=1;i<=n;i++)
  {
    cin>>inorder[i];
  }
  node* root=Create(1,n,1,n);
  postOrder(root);
  cout<<postorder[0]<<endl;
  return 0;
}
