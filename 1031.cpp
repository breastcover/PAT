#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
  char zm[11]={'1','0','X','9','8','7','6','5','4','3','2'};
  vector<string> vec;
  vector<string> res;
  for(int i=0;i<n;i++)
  {
    string tmp;
    cin>>tmp;
    vec.push_back(tmp);
  }


  for(int i=0;i<n;i++)
  {
    int tmp=0;
    int j=0;
    for(j;j<17;j++)
    {
      if(vec[i][j]>='0'&&vec[i][j]<='9')
        tmp=tmp+(vec[i][j]-'0')*weight[j];
      else
        break;
    }


    tmp%=11;

    if(zm[tmp]!=vec[i][17]||j!=17)
      res.push_back(vec[i]);
  }
  if(res.size()==0)
    cout<<"All passed"<<endl;
  else
  for(int i=0;i<res.size();i++)
  {
    cout<<res[i]<<endl;
  }
  return 0;
}
