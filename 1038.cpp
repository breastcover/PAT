#include <iostream>
using namespace std;

#define N 101

int main()
{
  int n;
  cin>>n;
  int num[N]={0};
  for(int i=0;i<n;i++)
  {
    int goals;
    cin>>goals;
    num[goals]++;
  }
  int m;
  cin>>m;
  int tmp;
  for(int i=0;i<m-1;i++)
  {

    cin>>tmp;
    cout<<num[tmp]<<' ';
  }
  cin>>tmp;
  cout<<num[tmp]<<endl;
  return 0;
}
