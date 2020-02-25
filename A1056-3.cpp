#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
  int Np,Ng;
  cin>>Np>>Ng;
  vector<int> w(Np);
  vector<int> res(Np);
  queue<int> q;
  for(int i=0;i<Np;i++)
    cin>>w[i];
  for(int i=0;i<Np;i++)
  {
    int sequence;
    cin>>sequence;
    q.push(sequence);
  }
  int n=Np,group;
  //cout<<1<<endl;
  while(q.size()!=1)
  {
    if(n%Ng==0)
      group=n/Ng;
    else
      group=n/Ng+1;
    for(int i=0;i<group;i++)
    {
      int max=-1,id;
      for(int j=0;j<Ng;j++)
      {
        if(i*Ng+j>=n) break;
        int tmp=q.front();
        q.pop();
        if(w[tmp]>max)
        {
          max=w[tmp];
          id=tmp;
        }
        res[tmp]=group+1;
      }
      q.push(id);
    }
    n=q.size();

  }
  //cout<<2<<endl;
  res[q.front()]=1;
  for(int i=0;i<Np;i++)
  {
    if(i==0)
      cout<<res[i];
    else
      cout<<" "<<res[i];
  }
  return 0;
}
