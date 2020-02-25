#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  node* lchild;
  node* rchild;
};

int n,index=0;;
vector<int> data(110);

void inorder(node* root)
{
  if(root==NULL)
    return ;
  inorder(root->lchild);
  root->data=data[index++];
  inorder(root->rchild);
}

void level_order(node* root)
{
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node* tmp=q.front();
    q.pop();
    cout<<tmp->data;
    if(tmp->lchild!=NULL)
      q.push(tmp->lchild);
    if(tmp->rchild!=NULL)
      q.push(tmp->rchild);
      if(q.size()!=0)
        cout<<' ';
  }
}


int main()
{
  cin>>n;
  vector<node> vec(n);
  for(int i=0;i<n;i++)
  {
    int l,r;
    cin>>l>>r;
    if(l!=-1)
      vec[i].lchild=&vec[l];
    if(r!=-1)
      vec[i].rchild=&vec[r];
  }
  for(int i=0;i<n;i++)
  {
    cin>>data[i];
  }
  sort(data.begin(),data.begin()+n);
  inorder(&vec[0]);
  level_order(&vec[0]);
  return 0;
}
