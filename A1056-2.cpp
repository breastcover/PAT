#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int np,ng;
  cin>>np>>ng;
  int npp=np;
  vector<int> v(np);
  for(int i=0;i<np;i++)
  {
    cin>>v[i];
  }
  vector<int> vec(np);
  vector<int> sequence(np);
  for(int i=0;i<np;i++)
  {
    int tmp;
    cin>>tmp;
    sequence[i]=tmp;
    vec[tmp]=v[i];
  }
  for(auto e:vec)
  cout<<e<<' ';
  cout<<endl;
  vector<int> help;
  vector<int> mid(np);
  for(int i=0;i<np;i++)
    mid[i]=i;
  vector<int> res(np,0);
  int n=np/ng;
  while(mid.size()>1)
  {
    for(int i=0;i<n;i++)
    {
      int _max=-1,win_id=0;
      for(int j=0;j<ng;j++)
      {
        res[mid[i*ng+j]]=n+1;
        if(vec[mid[i*ng+j]]>_max)
        {
          _max=vec[mid[i*ng+j]];
          win_id=mid[i*ng+j];
        }
      }
      help.push_back(win_id);
      res[win_id]=1;
    }
    int _max=-1,win_id=0;
    for(int j=n*ng;j<np;j++)
    {
      cout<<mid[j]<<endl;
      if(vec[mid[j]]>_max)
      {
        _max=vec[mid[j]];
        win_id=mid[j];
      }
    }
    help.push_back(win_id);
    res[win_id]=1;
    for(auto e:help)
      cout<<e<<' ';
    cout<<endl;
    mid.clear();
    mid=help;
    np=help.size();
    n=np/ng;
    help.clear();
  }
  vector<int> out(npp);

  for(int i=0;i<npp;i++)
  {
    out[i]=res[sequence[i]];
  }
  for(auto e:out)
    cout<<e<<' ';
  return 0;
}
