#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
  }
  vector<int> sorted=vec;
  sort(sorted.begin(),sorted.end());
  int _max=-1;
  vector<int> res;
  for(int i=0;i<n;i++)
  {
    if(_max<vec[i])
      _max=vec[i];
    if(vec[i]==sorted[i]&&_max==vec[i])
      res.push_back(vec[i]);
  }
  cout<<res.size()<<endl;
  for(int i=0;i<res.size();i++)
  {
    if(i==0)
      cout<<res[i];
    else
      cout<<' '<<res[i];
  }
  cout<<endl;
  return 0;
}
