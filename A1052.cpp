#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct node
{
  int date;
  int next;
}Node[100010];

struct nd
{
  int addr;
  int date;
};

bool cmp(nd n1,nd n2)
{
  return n1.date<n2.date;
}

int main()
{
  int n,first;
  cin>>n>>first;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    cin>>Node[tmp].date>>Node[tmp].next;
  }
   vector<nd> vec;
   for(int p=first;p!=-1;p=Node[p].next)
  {
    nd t;
    t.addr=p;
    t.date=Node[p].date;
    vec.push_back(t);
  }
  sort(vec.begin(),vec.end(),cmp);
  if(vec.size()>0)
  {
    cout<<vec.size()<<' ';
    printf("%05d\n",vec[0] );
    for(int i=0;i<vec.size()-1;i++)
    {
      printf("%05d %d %05d\n",vec[i].addr,vec[i].date,vec[i+1].addr);
    }
    printf("%05d %d -1\n",vec[vec.size()-1].addr,vec[vec.size()-1].date);
  }
  else
    cout<<"0 -1"<<endl;

  return 0;
}
