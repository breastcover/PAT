#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int rate[24];
int dayPrice=0;

struct Record
{
  string name;
  int month;
  int day;
  int hour;
  int minite;
  string status;
};

bool cmp(Record r1,Record r2)
{
  if(r1.name==r2.name)
  {
    if(r1.month==r2.month)
    {
      if(r1.day==r2.day)
      {
        if(r1.hour==r2.hour)
        {
          return r1.minite<r2.minite;
        }else
          return r1.hour<r2.hour;
      }else
      return r1.day<r2.day;
    }else
    return r1.month<r2.month;
  }
  return r1.name<r2.name;
}

double price(Record r1,Record r2)
{
  double res=0;
  int _day=r2.day-r1.day;
  if(_day>0)
  {
    res+=_day*dayPrice*60;
  }
  for(int i=0;i<r1.hour;i++)
  {
    res-=(rate[i]*60);
  }
  res-=(rate[r1.hour]*r1.minite);
  for(int i=0;i<r2.hour;i++)
  {
    res+=(rate[i]*60);
  }
  res+=(rate[r2.hour]*r2.minite);
  return res/100;
}

int _minites(Record r1,Record r2)
{
  int res=0;
  int _day=r2.day-r1.day;
  if(_day>0)
  {
    res+=_day*60*24;
  }
  for(int i=0;i<r1.hour;i++)
  {
    res-=60;
  }
  res-=r1.minite;
  for(int i=0;i<r2.hour;i++)
  {
    res+=60;
  }
  res+=r2.minite;
  return res;
}

int main()
{
  for(int i=0;i<24;i++)
  {
    cin>>rate[i];
    dayPrice+=rate[i];
  }
  //cout<<dayPrice<<endl;
  int n;
  cin>>n;
  vector<Record> vec(n);
  for(int i=0;i<n;i++)
  {
    cin>>vec[i].name;
    scanf("%d:%d:%d:%d",&vec[i].month,&vec[i].day,&vec[i].hour,&vec[i].minite);
    cin>>vec[i].status;
  }
  sort(vec.begin(),vec.end(),cmp);
  double monthsum=0;
  string _name;
  // cout<<"------Sorted-----"<<endl;
  // for(auto e:vec)
  // {
  //   cout<<e.name;
  //   printf(" %02d:%02d:%02d:%02d ",e.month,e.day,e.hour,e.minite);
  //   cout<<e.status<<endl;
  // }
  for(int i=0;i<n;i++)
  {

    double p=0;
    if(vec[i].name==vec[i+1].name&&vec[i].status=="on-line"&&vec[i+1].status=="off-line")
    {
        p=price(vec[i],vec[i+1]);
        if(p)
        {
          if(_name!=vec[i].name)
          {
            printf("%s %02d\n",vec[i].name.c_str(),vec[i].month );
            _name=vec[i].name;
          }
          printf("%02d:%02d:%02d ",vec[i].day,vec[i].hour,vec[i].minite );
          printf("%02d:%02d:%02d ",vec[i+1].day,vec[i+1].hour,vec[i+1].minite );
        }
        double p=price(vec[i],vec[i+1]);
        int _m=_minites(vec[i],vec[i+1]);
        printf("%d ",_m );
        printf("$%.2f\n",p);
        monthsum+=p;

    }
    else if(vec[i].name!=vec[i+1].name&&monthsum)
    {

      printf("Total amount: $%.2f\n",monthsum);

      monthsum=0;
    }

  }
  return 0;
}
