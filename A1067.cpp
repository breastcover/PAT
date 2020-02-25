#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n);
  int start;
  int mmp[n];
  for(int i=0;i<n;i++)
  {
    cin>>vec[i];
    mmp[vec[i]]=i;

  }

  int cnt=0;
  for(int i=1;i<n;i++)
  {
    if(mmp[i]!=i)
    {
      while(mmp[0]!=0)
      {
        swap(mmp[0],mmp[mmp[0]]);
        cnt++;
      }
      if(i!=mmp[i])
      {
        swap(mmp[0],mmp[i]);
        cnt++;
      }
    }

  }
  cout<<cnt<<endl;
  return 0;
}
