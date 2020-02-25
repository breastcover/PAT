#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  node* lchild;
  node* rchild;
};

int cnt=0;
int n;

bool level_order(node* root,int &lastnode)
{
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node* tmp=q.front();
    q.pop();
    if(tmp!=NULL)
    {
      //cout<<cnt<<endl;
      cnt++;
      lastnode=tmp->data;
      q.push(tmp->lchild);
      q.push(tmp->rchild);
    }else
    {
      if(cnt==n)
        return true;
      return false;
    }
  }
}

int main()
{

  cin>>n;
  vector<node> vec(n);
  vector<bool> haveparent(n,false);
  for(int i=0;i<n;i++)
  {
    string l,r;
    cin>>l>>r;
    vec[i].data=i;
    if(isdigit(l[0]))
    {
      vec[i].lchild=&vec[stoi(l)];
      haveparent[stoi(l)]=true;
    }
    if(isdigit(r[0]))
    {
      vec[i].rchild=&vec[stoi(r)];
      haveparent[stoi(r)]=true;
    }
  }
  int root;
  for(int i=0;i<n;i++)
  {
    if(haveparent[i]==false)
    {
      root=i;
      break;
    }
  }
  int lastnode;
  if(level_order(&vec[root],lastnode))
  {
    cout<<"YES"<<' '<<lastnode<<endl;
  }
  else
    cout<<"NO"<<' '<<root<<endl;
}
