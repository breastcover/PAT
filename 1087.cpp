#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int main()
{
  map<int,int> m;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    int tmp=floor((double)i/2)+floor((double)i/3)+floor((double)i/5);
    m[tmp]++;
  }
  cout<<m.size()<<endl;
  return 0;
}
