#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
  int first,n;
  cin>>first>>n;
  int data[100010],next[100010];
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    cin>>data[tmp]>>next[tmp];
  }
  vector<int> list;
  while(first!=-1)
  {
    list.push_back(first);
    first=next[first];
  }
  vector<int> res;
  vector<int> del;
  vector<int> times(10010,0);
  for(int i=0;i<list.size();i++)
  {
    int k=abs(data[list[i]]);
    if(times[k]==0)
    {
      res.push_back(list[i]);
      times[k]=1;
    }else
      del.push_back(list[i]);
  }
  for(int i=0;i<res.size()-1;i++)
  {
    printf("%05d %d %05d\n",res[i],data[res[i]],res[i+1]);
  }
  if(res.size()>0)
  printf("%05d %d -1\n",res[res.size()-1],data[res[res.size()-1]]);

  if(del.size()>0)
  {
    for(int i=0;i<del.size()-1;i++)
    {
      printf("%05d %d %05d\n",del[i],data[del[i]],del[i+1]);
    }
    printf("%05d %d -1\n",del[del.size()-1],data[del[del.size()-1]]);
  }
  return 0;
}
