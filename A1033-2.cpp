#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct station
{
  double distance;
  double price;
};

bool cmp(station s1,station s2)
{
  return s1.distance<s2.distance;
}

int main()
{
  double cmax,d,davg;
  int n;
  cin>>cmax>>d>>davg>>n;
  vector<station> vec(n+1);
  vec[0]={d,0.0};
  for(int i=1;i<=n;i++)
  {
    station s;
    cin>>s.price>>s.distance;
    vec[i]=s;
  }
  sort(vec.begin(),vec.end(),cmp);
  if(vec[0].distance!=0)
  {
    printf("The maximum travel distance = 0.00\n");
    return 0;
  }
  double left_gas_d=0;
  int index=0;
  double distance=0;
  double max_d=cmax*davg;
  double total_price=0;
  while(distance<d)
  {
    double min_price=1e8;
    int tmp_d=distance,tmp_index=index,flag=0;
    for(int i=index+1;i<=n&&vec[i].distance-vec[index].distance<=max_d;i++)
    {
      if(vec[i].price<vec[index].price)
      {
        total_price+=(vec[i].distance-vec[index].distance-left_gas_d)/davg*vec[index].price;
        left_gas_d=0;
        distance=vec[i].distance;
        flag=1;
        index=i;
        break;
      }

      if(vec[i].price<min_price)
      {
        min_price=vec[i].price;
        tmp_d=vec[i].distance;
        tmp_index=i;
      }

    }
    if(min_price!=1e8&&flag==0)
    {
      total_price+=(max_d-left_gas_d)/davg*vec[index].price;
      left_gas_d=max_d-(tmp_d-distance);
      distance=tmp_d;
      index=tmp_index;
    }
    if(min_price==1e8&&flag==0)
    {
      distance+=max_d;
      printf("The maximum travel distance = %.2f\n",distance);
      return 0;
    }
  }

  printf("%.2f\n",total_price);

  return 0;
}
