#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> vec(n+2);
  vec[0]=0;
  vec[1]=0;
  for(int i=2;i<=n+1;i++)
  {
    cin>>vec[i];
    vec[i]+=vec[i-1];
  }
  // for(int e:vec)
  //   cout<<e<<' ';
  //cout<<endl;
  int m;
  cin>>m;
  for(int i=0;i<m;i++)
  {
    int a, b;
    cin>>a>>b;
    if(a>b)
      swap(a,b);
    cout<<min(vec[b]-vec[a],vec[n+1]-(vec[b]-vec[a]))<<endl;
  }
  return 0;
}
