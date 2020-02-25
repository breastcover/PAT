#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int first,n,p;
  cin>>first>>n>>p;
  int date[100005],next[100005],list[100005];
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    cin>>date[tmp]>>next[tmp];
  }
  int sum=0;
  while(first!=-1)
  {
    list[sum++]=first;
    first=next[first];
  }
  for(int i=0;i<(sum-sum%p);i+=p)
  {
    reverse(begin(list)+i,begin(list)+i+p);
  }
  for(int i=0;i<sum-1;i++)
  {
    printf("%05d %d %05d\n",list[i],date[list[i]],list[i+1]);
  }
  printf("%05d %d -1",list[sum-1],date[list[sum-1]]);
  return 0;
}
