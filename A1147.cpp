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

int n,m;
vector<node*> vec(1001,NULL);
vector<int> post;

void vecdit()
{
  bool maxheap=true,minheap=true;
  for(int i=1;i<=n;i++)
  {
    if(i*2<=n&&vec[i]->data>vec[i*2]->data)
      minheap=false;
    if(i*2+1<=n&&vec[i]->data>vec[i*2+1]->data)
      minheap=false;
  }
  for(int i=1;i<=n;i++)
  {
    if(i*2<=n&&vec[i]->data<vec[i*2]->data)
      maxheap=false;
    if(i*2+1<=n&&vec[i]->data<vec[i*2+1]->data)
      maxheap=false;
  }
  if(minheap)
    cout<<"Min Heap"<<endl;
  else if(maxheap)
    cout<<"Max Heap"<<endl;
  else
    cout<<"Not Heap"<<endl;
}

node* Create()
{
  for(int i=1;i<=n;i++)
  {
    if(i*2<=n)
      vec[i]->lchild=vec[i*2];
    if(i*2+1<=n)
      vec[i]->rchild=vec[i*2+1];
  }
  return vec[1];
}

void postOrder(node* root)
{
  //cout<<1<<endl;
  if(root==NULL)
    return ;
  postOrder(root->lchild);
  postOrder(root->rchild);

  post.push_back(root->data);
}

int main()
{
  cin>>m>>n;
  while(m--)
  {
    for(int i=1;i<=n;i++)
    {
      int tmp;
      cin>>tmp;
      node* root=new node;
      root->data=tmp;
      root->lchild=root->rchild=NULL;
      vec[i]=root;
    }
    vecdit();
    node* root=Create();
    postOrder(vec[1]);
    for(int i=0;i<post.size();i++)
    {
      if(i==0)
        cout<<post[i];
      else
        cout<<" "<<post[i];
    }
    cout<<endl;
    post.clear();
  }
  return 0;
}
