#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  int heigth;
  node* lchild;
  node* rchild;
};

int n,max_heigth=-1;;
vector<int> post(35);
vector<int> in(35);

node* newNode(int data)
{
  node* root=new node;
  root->data=data;
  root->lchild=root->rchild=NULL;
  return root;
}

node* create(int postL,int postR,int inL,int inR,int heigth)
{
  if(postL>postR)
    return NULL;
  node* root=newNode(post[postR]);
  root->heigth=heigth;
  if(heigth>max_heigth)
    max_heigth=heigth;
  int k;
  for(k=inL;k<=inR;k++)
  {
    if(post[postR]==in[k])
      break;
  }
  int numLeft=k-inL;
  root->lchild=create(postL,postL+numLeft-1,inL,k-1,heigth+1);
  root->rchild=create(postL+numLeft,postR-1,k+1,inR,heigth+1);
  return root;
}

vector<node*> res[35];

void levelorder(node* root)
{
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node* tmp=q.front();
    q.pop();
    res[tmp->heigth].push_back(tmp);

    if(tmp->lchild)
    q.push(tmp->lchild);
    if(tmp->rchild)
    q.push(tmp->rchild);

  }
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    cin>>in[i];
  for(int i=1;i<=n;i++)
    cin>>post[i];
  node* root=create(1,n,1,n,1);
  levelorder(root);
  for(int i=1;i<=max_heigth;i++)
  {
    if(i%2==0)
    {
      for(int j=0;j<res[i].size();j++)
      {
          cout<<' '<<res[i][j]->data;
      }
    }else
    {
      for(int j=res[i].size()-1;j>=0;j--)
      {
        if(i==1)
          cout<<res[i][j]->data;
        else
          cout<<' '<<res[i][j]->data;
      }
    }
  }
  return 0;
}
