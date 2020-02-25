#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> p(n+1);
  for(int i=1;i<=n;i++)
  {
    cin>>p[i];
  }
  for(int i=1;i<n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      vector<int> a(n+1,1);
      vector<int> lie;
      a[i]=a[j]=-1;
      for(int k=1;k<=n;k++)
      {
        if(p[k]*a[abs(p[k])]<0)
          lie.push_back(k);
      }
      if(lie.size()==2&&a[lie[0]]+a[lie[1]]==0)
      {
        cout<<i<<' '<<j<<endl;
        return 0;
      }
    }
  }
  cout<<"No Solution"<<endl;
  return 0;
}
