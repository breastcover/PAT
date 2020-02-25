#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;


int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int flag=0;
    int d;
    cin>>d;
    string s=to_string(d);
    for(int j=1;j<10;j++)
    {
      int tmp=j*d*d;
      string res=to_string(tmp);
      if(res.substr(res.size()-s.size())==s)
      {
        flag=1;
        cout<<j<<' '<<tmp<<endl;
        break;
      }
    }
    if(!flag)
    cout<<"No"<<endl;
  }
  return 0;
}
