#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
  int n,full_credit;
  cin>>n>>full_credit;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
  {
    int sum=0,k=0;
    int major;
    cin>>major;
    int max=0,min=full_credit+1;
    for(int j=1;j<n;j++)
    {
      int tmp;
      cin>>tmp;
      if(tmp>=0&&tmp<=full_credit)
      {
        if(tmp>max)
          max=tmp;
        if(tmp<min)
          min=tmp;
        sum+=tmp;
        k++;
      }
    }
    //cout<<sum<<' '<<max<<' '<<min<< endl;
    double g=(double)(sum-max-min)/(k-2);
    vec[i]=round((g+major)/2);
  }
  for(int d:vec)
  cout<<d<<endl;
  return 0;
}
