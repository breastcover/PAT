#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
  int first,k,n;
  cin>>first>>n>>k;
  vector<int> data(100001);
  vector<int> next(100001);
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    cin>>data[tmp]>>next[tmp];
  }
  vector<int> list;
  vector<int> list2;
  vector<int> list3;
  while(first!=-1)
  {
    if(data[first]<0)
      list.push_back(first);
    else if(data[first]>k)
      list3.push_back(first);
    else
      list2.push_back(first);
    first=next[first];
  }
  list.insert(list.end(),list2.begin(),list2.end());
  list.insert(list.end(),list3.begin(),list3.end());
  for(int i=0;i<list.size();i++)
  {
    if(i!=list.size()-1)
    printf("%05d %d %05d\n",list[i],data[list[i]],list[i+1]);
    else
    printf("%05d %d -1\n",list[i],data[list[i]]);
  }
  return 0;
}
