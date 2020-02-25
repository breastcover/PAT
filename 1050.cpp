#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


int main()
{
   int n;
   cin>>n;
   vector<int> vec;
   for(int i=0;i<n;i++)
   {
     int tmp;
     cin>>tmp;
     vec.push_back(tmp);
   }
   sort(vec.begin(),vec.end());
   int col=sqrt(n);
   while(n%col!=0)
   {
     col--;
   }
   int row=n/col;

   int x[4]={0,1,0,-1};
   int y[4]={1,0,-1,0};
   int res[row][col];
   int vis[row][col];
   for(int i=0;i<row;i++)
   {
     for(int j=0;j<col;j++)
        vis[i][j]=false;
   }

    int k=0;
    int xx=0,yy=0;
   while(n--)
   {
     vis[xx][yy]=true;
     res[xx][yy]=vec[n];
  
     int xx1=xx+x[k];
     int yy1=yy+y[k];
     if(xx1<0||xx1>=row||yy1<0||yy1>=col||vis[xx1][yy1])
        k=(k+1)%4;
    xx+=x[k];
    yy+=y[k];
   }
   for(int i=0;i<row;i++)
   {
     for(int j=0;j<col-1;j++)
     {
       cout<<res[i][j]<<' ';
     }
     cout<<res[i][col-1]<<endl;
   }
   return 0;
}
