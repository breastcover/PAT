#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=0;i<k;i++)
  {
    stack<int> T;
    int num=1;
    int a[m+1];
    for(int j=1;j<=m;j++)
    {
      cin>>a[j];
    }
    int flag=1;
    for(int j=1;j<=m;j++)
    {
      int tmp=a[j];
      while(num<=tmp)
      {
        T.push(num++);
      }
      if(T.size()>n)
      {
        flag=0;
        cout<<"NO"<<endl;
        break;
      }
      if(T.top()==tmp)
      {
        T.pop();
      }
      if(j==m&&T.size()!=0)
      {
        flag=0;
        cout<<"NO"<<endl;
        break;
      }
    }
    if(flag)
    cout<<"YES"<<endl;
  }
  return 0;
}
