#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

int main()
{
  int m,n,tol;
  cin>>n>>m>>tol;
  int pic[m][n];
  int px[8]={-1,-1,-1,1,1,1,0,0};
  int py[8]={-1,0,1,-1,0,1,1,-1};
  map<string,int> mapp;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin>>pic[i][j];
      mapp[to_string(pic[i][j])]++;
    }
  }

  // for(int i=0;i<m;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
  //     printf("%-10d",pic[i][j]);
  //   }
  //   cout<<endl;
  // }
  int sum=0;
  int x,y;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      int k=0;
      int flag=1;
      while(k<8)
      {
        int dx=i+px[k];
        int dy=j+py[k];
        if(dx>=0&&dx<m&&dy>=0&&dy<n&&abs(pic[dx][dy]-pic[i][j])<=tol) flag=0;
        k++;
      }
      if(flag&&mapp[to_string(pic[i][j])]==1)
      {
        x=i;
        y=j;
        sum++;
      }
    }
    if(sum>1)
    {
      cout<<"Not Unique"<<endl;
      break;
    }
  }
  if(sum==1)
  cout<<'('<<y+1<<','<<' '<< x+1<<')'<<':'<<' ' <<pic[x][y]<<endl;
  if(sum==0)
  cout<<"Not Exist"<<endl;
  return 0;
}
