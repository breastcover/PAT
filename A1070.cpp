#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct mooncake
{
  double weigt;
  double price;
  double per_price;
};

bool cmp(mooncake m1,mooncake m2)
{
  return m1.per_price>m2.per_price;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<mooncake> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].weigt;
  }
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].price;
    vec[i].per_price=vec[i].price/vec[i].weigt;
  }

  sort(vec.begin(),vec.end(),cmp);
  double res=0;
  int index=0;
  while(m&&index<n)
  {
    if(m>=vec[index].weigt)
    {
      res+=vec[index].price;
      m-=vec[index].weigt;
    }else if(m<vec[index].weigt)
    {
      res+=(m*vec[index].per_price);
      m=0;
    }
    index++;
  }
  printf("%.2f\n",res);
  return 0;
}
