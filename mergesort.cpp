#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge_sort(vector<int> vec,vector<vector<int> merge_res)
{
  int n=vec.size();
  for(int i=1;i<2*n;i*=2)
  {
    for(int j=0;j<n/i;j++)
    {
      sort(vec.begin()+i*j,vec.begin()+(j+1)*i);
    }
    sort(vec.begin()+i*(n/i),vec.end());
    merge_res.push_back(vec);
    // for(int i=0;i<vec.size();i++)
    // {
    //   cout<<vec[i]<<' ';
    // }
    // cout<<endl;
  }
  return merge_res;
}

int main()
{
  int n;
  cin>>n;
  vector<int> vec;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    vec.push_back(tmp);
  }
  merge_sort(vec);
  for(int i=0;i<)
  return 0;
}
