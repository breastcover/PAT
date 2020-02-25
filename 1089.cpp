#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> lie;
  vector<int> a(n+1,1);
  vector<int> t(n+1,0);
  for(int i=1;i<=n;i++)
  {
    cin>>t[i];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      a[i]=a[j]=-1;
      lie.clear();
      for(int k=1;k<=n;k++)
      {

        if(t[k]*a[abs(t[k])]<0)
          lie.push_back(k);

      }
      if(lie.size()==2&&a[lie[0]]+a[lie[1]]==0)
      {
         cout<<i<<' '<<j<<endl;
         return 0;
      }

      a[i]=a[j]=1;
    }

  }
  cout<<"No Solution"<<endl;
  return 0;
}
