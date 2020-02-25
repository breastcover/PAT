#include <iostream>
#include <vector>
using namespace std;

int main()
{
  double coefficients[1010]={0};
  bool vis[1010]={false};
  int num=0;
  for(int i=0;i<2;i++)
  {
    int a,n;
    double b;
    cin>>n;
    for(int j=0;j<n;j++)
    {
      cin>>a>>b;
      coefficients[a]+=b;
      if(vis[a]==false)
        num++;
      else if(coefficients[a]==0)
        num--;
      vis[a]=true;
    }
  }
  cout<<num;
  for(int i=1009;i>=0;i--)
  {
    if(coefficients[i]!=0)
      printf(" %d %.1f",i,coefficients[i]);
  }
  return 0;
}
