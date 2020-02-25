#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  long long p;
  cin>>n>>p;
  vector<long long> vec;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    vec.push_back(tmp);
  }
  sort(vec.begin(),vec.end());
  long long res=0;
  for(int i=0;i<vec.size();i++)
  {
      long long tmp;
      for(int j=i+res;j<vec.size();j++)
      {
        if(vec[i]*p>=vec[j])
          tmp=j-i+1;
        else
          break;

      }
      if(tmp>res)
      res=tmp;
  }
  cout<<res<<endl;
  return 0;
}
