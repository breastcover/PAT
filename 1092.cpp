#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> vec(n,0);
  int max=-1;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      int tmp;
      cin>>tmp;
      vec[j]+=tmp;
      if(vec[j]>max)
        max=vec[j];
    }
  }
  cout<<max<<endl;
  int flag=1;
  for(int i=0;i<n;i++)
    if(vec[i]==max)
    {
      if(flag)
      {
        cout<<i+1;
        flag=0;
      }
      else
      cout<<' '<<i+1;
    }
  cout<<endl;
  return 0;
}
