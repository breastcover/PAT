#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
  int data;
  int times;
};

int main()
{
  int n;
  cin>>n;
  int t[100010]={0};
  vector<int> vec;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    t[tmp]++;
    vec.push_back(tmp);
  }
  int flag=1;
  for(int i=0;i<n;i++)
  {
    if(t[vec[i]]==1)
    {
      flag=0;
      cout<<vec[i]<<endl;
      break;
    }
  }
  if(flag)
    cout<<"None"<<endl;
  return 0;
}
