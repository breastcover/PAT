#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
  return a>b;
}

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  sort(vec.begin(),vec.end());
  int col=sqrt(n);
  while(n%col!=0)
  {
    col--;
  }
  int row=n/col;
  int res[row][col];
  bool vis[row][col];
  fill(vis[0],vis[0]+n,false);
  int index=1;
  int x[4]={0,1,0,-1};
  int y[4]={1,0,-1,0};
  int k=0;
  int xx=0,yy=0;
  while(n--)
  {
    vis[xx][yy]=true;
    res[xx][yy]=vec[n];
    int xx1=xx+x[k];
    int yy1=yy+y[k];
    if(vis[xx1][yy1]||xx1<0||xx1>=row||yy1<0||yy1>=col)
    {
      k=(k+1)%4;
    }
    xx+=x[k];
    yy+=y[k];
  }
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(j==0)
      cout<<res[i][j];
      else
      cout<<' '<<res[i][j];
    }
    cout<<endl;
  }
  return 0;
}
