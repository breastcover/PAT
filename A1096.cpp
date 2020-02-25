#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


int main()
{
  int n;
  cin>>n;
  int t=n;
  int large_length=0;
  int tmp_length=0;
  vector<int> res;
  vector<int> help;
  int flag=0;
  for(int i=2;i<=sqrt(t);i++)
  {
    for(int j=i;j<n;j++)
    {
      if(n==0)
        break;
      if(n%j==0)
      {
        //cout<<n<<' '<<j<<endl;
        n/=j;
        if(j==flag+1)
        {
          tmp_length++;
          help.push_back(j);
        }
        else
        {
          tmp_length=1;
          help.clear();
          help.push_back(j);
        }
        flag=j;
        if(large_length<tmp_length)
        {
          large_length=tmp_length;
          res.clear();
          res=help;
        }
      }
      else
        break;
    }
    //cout<<endl;
    n=t;
  }
  if(large_length==0)
  {
    cout<<1<<endl;
    cout<<t<<endl;
    return 0;
  }
  cout<<large_length<<endl;
  for(int i=0;i<res.size();i++)
  {
    if(i==0)
      cout<<res[i];
    else
      cout<<'*'<<res[i];
  }
  return 0;
}
