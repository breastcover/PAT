#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int a[100010]={0};
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    if(tmp>0&&tmp<100010)
      a[tmp]=1;
  }
  for(int i=1;i<100010;i++)
  {
    if(a[i]==0)
    {
      cout<<i<<endl;
      break;
    }
  }
  return 0;
}
