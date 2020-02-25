#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_solution(vector<int> vec)
{
  for(int i=0;i<vec.size();i++)
  {
    for(int j=i+1;j<vec.size();j++)
    {
      if(vec[i]==vec[j])
        return false;
      if(abs(i-j)==abs(vec[i]-vec[j]))
      {   //cout<<i<<' '<<j<<endl;
          //cout<<vec[i]<<' '<<vec[j]<<endl;
          return false;}
    }
  }
  return true;
}

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int m;
    cin>>m;
    vector<int> vec(m);
    for(int j=0;j<m;j++)
    {
      cin>>vec[j];
    }
    if(is_solution(vec))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }

  return 0;
}
