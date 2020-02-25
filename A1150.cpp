#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  int G[n+1][n+1];
  fill(G[0],G[0]+(n+1)*(n+1),-1);
  for(int i=0;i<m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
    G[a][b]=w;
    G[b][a]=w;
  }
  int k,_min_p=1e8,_min_k;
  cin>>k;
  for(int i=0;i<k;i++)
  {
    int nc,st,start,isTSsc=0,isTSc=0,NA=0;
    cin>>nc;
    int sum=0;
    cin>>st;
    start=st;
    set<int> s;
    s.insert(st);
    for(int j=1;j<nc;j++)
    {
      int next;
      cin>>next;
      if(G[st][next]!=-1)
        sum+=G[st][next];
      else
      {
        NA=1;
      }
      st=next;
      s.insert(st);
    }
    if(s.size()==n&&start==st)
    {
      isTSc=1;
      if(nc==s.size()+1)
        isTSsc=1;
    }
    if(isTSc)
    {
      if(sum<_min_p)
      {
        _min_p=sum;
        _min_k=i+1;
      }
    }
    if(NA)
      cout<<"Path "<<i+1<<": "<<"NA"<<" (Not a TS cycle)"<<endl;
    else if(isTSsc)
      cout<<"Path "<<i+1<<": "<<sum<<" (TS simple cycle)"<<endl;
    else if(isTSc)
      cout<<"Path "<<i+1<<": "<<sum<<" (TS cycle)"<<endl;
    else
      cout<<"Path "<<i+1<<": "<<sum<<" (Not a TS cycle)"<<endl;
  }
  cout<<"Shortest Dist("<<_min_k<<") = "<<_min_p<<endl;
  return 0;
}
