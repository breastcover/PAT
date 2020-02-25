#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;

const double eps=1e-8;

double _distance(double x,double y)
{
  return sqrt(pow(x,2)+pow(y,2));
}

int main()
{
  int n;
  cin>>n;
  string win;
  string noob;
  double x,y;
  double max=0,min=200;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s>>x>>y;
    if(min-_distance(x,y)>eps)
    {
       min=_distance(x,y);
       win=s;
    }
    if(_distance(x,y)-max>eps)
    {
        max=_distance(x,y);
        noob=s;
    }
  }
  cout<<win<<" "<<noob<<endl;
  return 0;
}
