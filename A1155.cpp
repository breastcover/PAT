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
vector<int> vec(1010);
vector<int> path;

void in_oder(node* root)
{
  if(root==NULL)
    return ;
  in_oder(root->lchild);
  cout<<root->data<<' ';
  in_oder(root->rchild);
}

void dfs(node* root)
{
  if(root==NULL)
    return ;
  path.push_back(root->data);
  if(root->lchild==NULL&&root->rchild==NULL)
  {
    for(int i=0;i<path.size();i++)
    {
      if(i==0)
        cout<<path[i];
      else
        cout<<' '<<path[i];
    }
    cout<<endl;
    path.pop_back();
    return ;
  }
  dfs(root->rchild);
  dfs(root->lchild);
  path.pop_back();
}


int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>vec[i];
  vector<node> heap(n+1);
  for(int i=1;i<=n;i++)
  {
    heap[i].data=vec[i];
    if(i*2<=n)
      heap[i].lchild=&heap[i*2];
    if(i*2+1<=n)
      heap[i].rchild=&heap[i*2+1];
  }
  //in_oder(&heap[1]);
  dfs(&heap[1]);
  bool minHeap=true,maxHeap=true;
  for(int i=1;i<=n;i++)
  {
    if(i*2<=n&&vec[i*2]>vec[i]||(i*2+1<=n&&vec[i*2+1]>vec[i]))
      maxHeap=false;
    if(i*2<=n&&vec[i*2]<vec[i]||(i*2+1<=n&&vec[i*2+1]<vec[i]))
      minHeap=false;
  }
  if(minHeap)
    cout<<"Min Heap"<<endl;
  else if(maxHeap)
    cout<<"Max Heap"<<endl;
  else
    cout<<"Not Heap"<<endl;
  return 0;
}
