#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

bool attend_find(vector<int> attend,int p)
{
  for(int i=0;i<attend.size();i++)
  {
    if(attend[i]==p)
      return true;
  }
  return false;
}

int main()
{
  int n;
  cin>>n;
  int parter[100010]={-1};

  for(int i=0;i<n;i++)
  {
    int tmp1;
    int tmp2;
    cin>>tmp1>>tmp2;
    parter[tmp1]=tmp2;
    parter[tmp2]=tmp1;
  }
  int m;
  cin>>m;
  vector<int> attend(m);
  for(int i=0;i<m;i++)
  {
      cin>>attend[i];
  }
  vector<int> res;
  for(int i=0;i<m;i++)
  {
    if(parter[attend[i]]==-1)
      res.push_back(attend[i]);
    else
    {
      if(!attend_find(attend,parter[attend[i]]))
      {
        res.push_back(attend[i]);
      }
    }
  }
  sort(res.begin(),res.end());
  cout<<res.size()<<endl;
  if(res.size()>0)
  {

    for(int i=0;i<res.size()-1;i++)
    {
      printf("%05d",res[i]);
      printf(" ");
    }
      printf("%05d\n",res[res.size()-1]);
  }

  return 0;
}
