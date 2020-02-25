#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> vec(10001);
  for(int i=1;i<=n;i++)
  {
    int tmp;
    cin>>tmp;
    vec[abs(tmp-i)]++;
  }
  for(int i=10001;i>=0;i--)
  {
    if(vec[i]>=2)
      cout<<i<<' '<<vec[i]<<endl;
  }
  return 0;
}
