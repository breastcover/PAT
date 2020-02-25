#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct subject
{
  vector<string> students;
};

int main()
{
  int n,m;
  cin>>n>>m;
  vector<subject> vec(m+1);
  for(int i=0;i<n;i++)
  {
    string name;
    int k;
    cin>>name>>k;
    for(int j=0;j<k;j++)
    {
      int tmp;
      cin>>tmp;
      vec[tmp].students.push_back(name);
    }
  }
  for(int i=1;i<=m;i++)
  {
    sort(vec[i].students.begin(),vec[i].students.end());
  }
  for(int i=1;i<=m;i++)
  {
    printf("%d %d\n",i,vec[i].students.size());
    for(int j=0;j<vec[i].students.size();j++)
    {
      printf("%s",vec[i].students[j].c_str());
      printf("\n");
    }
  }
  return 0;
}
