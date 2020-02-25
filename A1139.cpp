#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
using namespace std;

struct node
{
  int a,b;
  node(int x,int y)
  {
    a=abs(x);
    b=abs(y);
  };
  ~node(){};
};

bool cmp(node n1,node n2)
{
  if(n1.a==n2.a)
    return n1.b<n2.b;
  return n1.a<n2.a;
}

int const MAX=9999;
int n,m,k;
map<int,bool> isFriend;
map<string,vector<string>> goodFriend;

int main()
{
  cin>>n>>m;
  for(int i=1;i<=m;i++)
  {
    string a,b;
    cin>>a>>b;
    isFriend[stoi(a)*10000+stoi(b)]=isFriend[stoi(b)*10000+stoi(a)]=true;
    if(a.size()==b.size())
    {
      goodFriend[a].push_back(b);
      goodFriend[b].push_back(a);
    }
  }
  cin>>k;
  for(int i=0;i<k;i++)
  {
    string a,b;
    cin>>a>>b;
    vector<node> res;
    for(int j=0;j<goodFriend[a].size();j++)
    {
      for(int l=0;l<goodFriend[b].size();l++)
      {
        if(goodFriend[a][j]==b||goodFriend[b][l]==a)
          continue;
        if(isFriend[stoi(goodFriend[a][j])*10000+stoi(goodFriend[b][l])]==true)
        {
          res.push_back(node(stoi(goodFriend[a][j]),stoi(goodFriend[b][l])));
        }
      }
    }
    sort(res.begin(),res.end(),cmp);
    cout<<res.size()<<endl;
    for(int j=0;j<res.size();j++)
    {
      printf("%04d %04d\n",res[j].a,res[j].b);
    }
  }
  return 0;
}
