#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> level(1010);
vector<int> vec(1010);
int index=0;

void level_order(int i)
{
  if(i>n)
    return ;
  level_order(i*2);
  level[i]=vec[index++];
  level_order(i*2+1);
}

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>vec[i];
  sort(vec.begin(),vec.begin()+n);
  level_order(1);
  for(int i=1;i<=n;i++)
  {
    cout<<level[i];
    if(i<n)
      cout<<' ';
  }
  return 0;
}
