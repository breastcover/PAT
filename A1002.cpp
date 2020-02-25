#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;


int main()
{
  map<int,double> m;
  int n1,n2;
  cin>>n1;
  int exponets;
  while(n1--)
  {

    cin>>exponets;
    cin>>m[exponets];
  }
  cin>>n2;
  while(n2--)
  {
    double tmp;
    cin>>exponets;
    cin>>tmp;
    m[exponets]+=tmp;
  }
  vector<pair<int,double>> vec;
  for(auto iter=m.begin();iter!=m.end();iter++)
  {
    if((int)iter->second!=0)
    vec.push_back(make_pair(iter->first,iter->second));
  }
  if(vec.size()>=1)
  {
    cout<<vec.size();
    for(auto iter=vec.end()-1;iter>=vec.begin();--iter)
    {
      printf(" %d %.1f",iter->first,iter->second );
    }
  }
  else
  cout<<0<<endl;
  
  return 0;
}
