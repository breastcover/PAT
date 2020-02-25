#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  char c;
  double n;
  cin>>n>>c;
  cout<<round(n/2)<<endl;
  for(int i=0;i<round(n/2);i++)
  {
    cout<<c;
    for(int j=1;j<n-1;j++)
    {
      if(i==0||i==round(n/2)-1)
        cout<<c;
      else
        cout<<' ';
    }
    cout<<c<<endl;
  }
  return 0;
}
