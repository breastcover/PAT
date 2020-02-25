#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int first,n,m;
  cin>>first>>n>>m;
  int next[100010],data[100010];
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    cin>>data[tmp]>>next[tmp];
  }
  int list[100010];
  int num=0;
  while(first!=-1)
  {
    list[num++]=first;
    first=next[first];
  }

  for(int i=0;i<(num-num%m);i+=m)
  {
    reverse(begin(list)+i,begin(list)+i+m);
  }
  // for(int i=0;i<num;i++)
  //   cout<<list[i]<<endl;
  for(int i=0;i<num-1;i++)
  {
    printf("%05d %d %05d\n",list[i],data[list[i]],list[i+1]);
  }
  printf("%05d %d -1",list[num-1],data[list[num-1]]);
  return 0;
}
