#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
  int date;
  node* lchild;
  node* rchild;
};

node* newNode(int v)
{
  node* Node=new node;
  Node->date=v;
  Node->lchild=Node->rchild=NULL;
  return Node;
}

void insert(node* &root,int x)
{
  if(root==NULL)
  {
    root=newNode(x);
    return ;
  }
  if(x<root->date)
  {
    insert(root->lchild,x);
  }else
  {
    insert(root->rchild,x);
  }
}

node* Create(int date[],int n)
{
  node* Node=NULL;
  for(int i=0;i<n;i++)
    insert(Node,date[i]);
  return Node;
}

void preOrder(node* Node,vector<int> &vec)
{
  if(Node==NULL)
  return;

  vec.push_back(Node->date);
  preOrder(Node->lchild,vec);
  preOrder(Node->rchild,vec);

}

void preOrderMirror(node* Node,vector<int> &vec)
{
  if(Node==NULL)
  return;
  vec.push_back(Node->date);
  preOrderMirror(Node->rchild,vec);
  preOrderMirror(Node->lchild,vec);
}

void postOrder(node* Node,vector<int> &vec)
{
  if(Node==NULL)
  return;
  postOrder(Node->lchild,vec);
  postOrder(Node->rchild,vec);
  vec.push_back(Node->date);

}

void postOrderMirror(node* Node,vector<int> &vec)
{
  if(Node==NULL)
  return;
  postOrderMirror(Node->rchild,vec);
  postOrderMirror(Node->lchild,vec);
  vec.push_back(Node->date);
}

int main()
{
  int n;
  cin>>n;
  int date[n];
  vector<int> origin;
  for(int i=0;i<n;i++)
  {
    cin>>date[i];
    origin.push_back(date[i]);
  }

  node* root=Create(date,n);
  // cout<<"Complete Create"<<endl;
  vector<int> pre;
  vector<int> preMirror;
  preOrder(root,pre);
  // cout<<"preOrder"<<endl;
  // for(int e:pre)
  // {
  //   cout<<e<<' ';
  // }
  // cout<<endl;
  preOrderMirror(root,preMirror);
  // cout<<"preOrderMirror"<<endl;
  // for(int e:preMirror)
  // {
  //   cout<<e<<' ';
  // }
  // cout<<endl;
  vector<int> res;
  if(pre==origin)
  {
    postOrder(root,res);
    cout<<"YES"<<endl;
    for(int i=0;i<res.size();i++)
    {
      if(i==0)
        cout<<res[i];
      else
        cout<<' '<<res[i];
    }
    cout<<endl;
  }else if(preMirror==origin)
  {
    postOrderMirror(root,res);
    cout<<"YES"<<endl;
    for(int i=0;i<res.size();i++)
    {
      if(i==0)
        cout<<res[i];
      else
        cout<<' '<<res[i];
    }
    cout<<endl;
  }
  else
    cout<<"NO"<<endl;
  return 0;
}
