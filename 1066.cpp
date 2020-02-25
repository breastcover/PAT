#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n,m,a,b,g;
  cin>>n>>m>>a>>b>>g;
  int pic[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int tmp;
      cin>>tmp;
      if(tmp>=a&&tmp<=b)
      {
        pic[i][j]=g;
      }
      else
        pic[i][j]=tmp;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(j!=0)
      printf(" ");
      printf("%03d",pic[i][j]);
    }
    printf("\n");
  }
  return 0;
}
