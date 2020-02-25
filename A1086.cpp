#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> pre;
vector<int> in;
vector<int> post;

struct node
{
  int data;
  node* lchild;
  node* rchild;
};

int findRoot(int l,int r,int p)
{
  int i=l;
  for(i=l;i<=r;i++)
  {
    if(in[i]==pre[p])
      break;
  }
  return i-l;
}

node* createTree(int preL,int preR,int inL,int inR)
{
  if(preL>preR)
  {
    return NULL;
  }
  node* root=new node;
  root->data=pre[preL];
  int k=findRoot(inL,inR,preL);
  root->lchild=createTree(preL+1,preL+k,inL,inL+k-1);
  root->rchild=createTree(preL+k+1,preR,inL+k+1,inR);
  return root;
}

void postOrder(node* root)
{
  if(root)
  {
    postOrder(root->lchild);
    postOrder(root->rchild);
    post.push_back(root->data);
  }
}

int main()
{
  int n;
  cin>>n;
  stack<int> t;
  for(int i=0;i<2*n;i++)
  {
    string s;
    cin>>s;
    if(s=="Push")
    {
      int a;
      cin>>a;
      t.push(a);
      pre.push_back(a);
    }
    else
    {
      int tmp=t.top();
      t.pop();
      in.push_back(tmp);
    }
  }
  node* root=createTree(0,n-1,0,n-1);
  postOrder(root);
  for(int i=0;i<post.size();i++)
  {
    if(i==0)
      cout<<post[i];
    else
      cout<<' '<<post[i];
  }
  cout<<endl;
  return 0;
}
