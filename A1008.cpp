#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int _floor[n+1];
  _floor[0]=0;
  int _time=0;
  for(int i=1;i<=n;i++)
  {
    cin>>_floor[i];
  }
  for(int i=1;i<=n;i++)
  {
    if(_floor[i]>_floor[i-1])
    {
      _time+=(_floor[i]-_floor[i-1])*6+5;
    }
    else
    {
      _time+=(_floor[i-1]-_floor[i])*4+5;
    }
  }
  cout<<_time<<endl;
  return 0;
}
