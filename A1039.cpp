#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
  int subjects;
  vector<int> s;
}node;

int main()
{
  int n,m;
  cin>>n>>m;
  map<string,Node> mmp;
  for(int i=0;i<m;i++)
  {
    int subject,num;
    cin>>subject>>num;
    for(int j=0;j<num;j++)
    {
      string name;
      cin>>name;
      mmp[name].s.push_back(subject);
      mmp[name].subjects++;
    }
  }
  for(int i=0;i<n;i++)
  {
    string tmp;
    cin>>tmp;
    cout<<tmp<<' '<<mmp[tmp].subjects;
    sort(mmp[tmp].s.begin(),mmp[tmp].s.end());
    for(auto e:mmp[tmp].s)
      cout<<' '<<e;
    cout<<endl;
  }
  return 0;
}
