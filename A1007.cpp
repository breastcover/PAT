#include <iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int num[n];
  for(int i=0;i<n;i++)
  {
    cin>>num[i];
  }
  int sum=0;
  int max=-1;
  int st=num[0],ed=num[n-1];
  int tmpst=num[0];
  for(int i=0;i<n;i++)
  {
    sum+=num[i];
    if(sum<0)
    {
      sum=0;
      tmpst=num[i+1];
    }else if(sum>max)
    {
      max=sum;
      ed=num[i];
      st=tmpst;
    }
  }
  if(max<0) max=0;
  cout<<max<<' '<<st<<' '<<ed<<endl;
  return 0;
}
