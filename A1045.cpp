#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int m;
  cin>>m;
  vector<int> vec(m);
  for(int i=0;i<m;i++)
  {
    cin>>vec[i];
  }
  vector<int> res(m,0);
  int l;
  cin>>l;
  for(int i=0;i<l;i++)
  {
    int tmp;
    cin>>tmp;
    for(int j=0;j<m;j++)
    {
      if(tmp==vec[0])
      {
        res[0]++;
        break;
      }else if(tmp==vec[j])
      {
        int _max=0;
        for(int t=0;t<=j;t++)
        {
          if(res[t]>_max)
          {
            _max=res[t];
          }
        }
        res[j]=_max+1;
        break;
      }
    }

  }

  cout<<res[m-1]<<endl;
  return 0;
}
