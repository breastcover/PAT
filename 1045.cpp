#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
  vector<int> sort_vec=vec;
  sort(sort_vec.begin(),sort_vec.end());
  vector<int> res;
  // vector<int> max(n,0);
  // max[0]=vec[0];
  // for(int i=1;i<n;i++)
  // {
  //   if(vec[i]>max[i-1])
  //     max[i]=vec[i];
  //   else
  //     max[i]=max[i-1];
  // }
  // for(int i=0;i<n;i++)
  // {
  //   cout<<max[i]<<' ';
  // }
  // cout<<endl;
  int max=-1;
  for(int i=0;i<n;i++)
  {
    if(max<vec[i])
    {
      max=vec[i];
      if(vec[i]==sort_vec[i])
        res.push_back(vec[i]);
    }
  }
  cout<<res.size()<<endl;

  for(int i=0;i<res.size();i++)
  {
    if(i==0)
    cout<<res[i];
    else
    cout<<' '<<res[i];
  }
  printf("\n");
  return 0;
}
