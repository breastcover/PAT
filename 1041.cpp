#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
  vector<pair<string,pair<int,int>>> vec;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int a,b;
    string s;
    cin>>s>>a>>b;
    vec.push_back(make_pair(s,make_pair(a,b)));
  }
  int m;
  cin>>m;
  for(int i=0;i<m;i++)
  {
    int tmp;
    cin>>tmp;
    for(auto iter=vec.begin();iter!=vec.end();iter++)
    {
      if(iter->second.first==tmp)
        cout<<iter->first<<" "<<to_string(iter->second.second)<<endl;
    }
  }
  return 0;
}
