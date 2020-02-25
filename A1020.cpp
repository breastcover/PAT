#include <iostream>
#include <queue>
using namespace std;

struct node
{
  int date;
  node *leftChild;
  node *rightChild;
};

int n;
int post[31];
int in[31];

node* CreateTree(int postL,int postR,int inL,int inR)
{
  if(postL>postR)
  {
    return NULL;
  }
  node* root=new node;
  root->date=post[postR];
  int k;
  for(k=inL;k<=inR;k++)
  {
    if(in[k]==post[postR])
    {
      break;
    }
  }
  int numLeft=k-inL;
  root->leftChild=CreateTree(postL,postL+numLeft-1,inL,k-1);
  root->rightChild=CreateTree(postL+numLeft,postR-1,k+1,inR);
  return root;
}

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>post[i];
  }
  for(int i=0;i<n;i++)
  {
    cin>>in[i];
  }
  node* root=CreateTree(0,n-1,0,n-1);
  queue<node*> q;
  q.push(root);
  cout<<root->date;
  while(!q.empty())
  {
    node* tmp=q.front();
    q.pop();
    if(tmp->leftChild!=NULL)
    {
      q.push(tmp->leftChild);
      cout<<' '<<tmp->leftChild->date;
    }
    if(tmp->rightChild!=NULL)
    {
      q.push(tmp->rightChild);
      cout<<' '<<tmp->rightChild->date;
    }
  }
  return 0;
}
