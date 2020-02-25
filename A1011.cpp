#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(double a,double b)
{
  return a>b;
}

char c[3]={'W','T','L'};

int main()
{
  double bet[3][3];
  for(int i=0;i<3;i++)
  {
    cin>>bet[i][0]>>bet[i][1]>>bet[i][2];
  }
  double res=1;
  for(int i=0;i<3;i++)
  {
    double max=0;
    int flag;
    for(int j=0;j<3;j++)
    {
      if(bet[i][j]>max)
      {
        max=bet[i][j];
        flag=j;
      }

    }
    cout<<c[flag]<<' ';
    res*=max;
  }
  printf("%.2f\n",(res*0.65-1)*2);
  return 0;
}
