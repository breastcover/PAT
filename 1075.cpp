#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
  int addr;
  int data;
  int next;
};

int main()
{
  int first,n,k;
  int data[100005],next[100005];
  cin>>first>>n>>k;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    cin>>data[tmp]>>next[tmp];
  }
  vector<node> vec;
  while(first!=-1)
  {
    node t;
    t.addr=first;
    t.data=data[first];
    t.next=next[first];
    first=next[first];
    vec.push_back(t);
  }
  vector<node> vec1;
  vector<node> vec2;
  vector<node> vec3;
  for(int i=0;i<vec.size();i++)
  {
    if(vec[i].data<0)
      vec1.push_back(vec[i]);
    else if(vec[i].data>=0&&vec[i].data<=k)
      vec2.push_back(vec[i]);
    else
      vec3.push_back(vec[i]);
  }
  vector<node> res=vec1;
  res.insert(res.end(),vec2.begin(),vec2.end());
  res.insert(res.end(),vec3.begin(),vec3.end());
  for(int i=0;i<res.size()-1;i++)
  {
    printf("%05d %d %05d\n",res[i].addr,res[i].data,res[i+1].addr);
  }
  printf("%05d %d -1\n",res[res.size()-1].addr,res[res.size()-1].data);
  return 0;
}
