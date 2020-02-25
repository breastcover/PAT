#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n,interval,start;
  cin>>n>>interval>>start;
  vector<string> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
  }
  vector<string> res;
  int k=start-1;
  while(k<n)
  {
    while(find(res.begin(),res.end(),vec[k])!=res.end())
    {
      k++;
    }
    res.push_back(vec[k]);
    k+=interval;
  }
  for(int i=0;i<res.size();i++)
  {
    cout<<res[i]<<endl;
  }
  if(res.size()==0)
  cout<<"Keep going..."<<endl;
  return 0;
}
