#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
  int hour;
  int minite;
  int second;
  int processing;
  node(){}
  node(int h,int m,int s)
  {
    hour=h;
    minite=m;
    second=s;
  }
  ~node(){}
};

struct window
{
  int endtime;
  queue<node> q;
};

bool before(node n)
{
  if(n.hour<8)
    return true;
  return false;
}
bool after(node n)
{
  if(n.hour>17)
    return true;
  if(n.hour==17)
  {
    if(n.minite>0||n.second>0)
    return true;
  }
  return false;
}

int _time_dif(node n1,node n2)
{
  int sum=0;
  int _hour=n2.hour-n1.hour;
  if(_hour)
  {
    sum+=_hour*60*60;
  }
  sum=sum-n1.minite*60-n1.second;
  sum=sum+n2.minite*60+n2.second;
  return sum;
}

bool cmp(node n1,node n2)
{
  if(n1.hour==n2.hour)
  {
    if(n1.minite==n2.minite)
    {
      return n1.second<n2.second;
    }
    return n1.minite<n2.minite;
  }
  return n1.hour<n2.hour;
}

double to_decimal(int n)
{
  return (double)n/60;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<window> vec(m);
  vector<node> p(n);
  int wait=0;
  for(int i=0;i<n;i++)
  {
    scanf("%d:%d:%d %d",&p[i].hour,&p[i].minite,&p[i].second,&p[i].processing);
  
  }
  //cout<<wait<<endl;
  sort(p.begin(),p.end(),cmp);
  int index=0;

  for(int i=0;i<m;i++)
  {
    vec[i].q.push(p[index]);
    vec[i].endtime=p[index].processing*60;
    // cout<<"first:"<<endl;
    // cout<<vec[i].endtime<<endl;
    index++;
  }
  for(int i=0;i<n;i++)
  {
    if(before(p[i]))
    {  wait+=_time_dif(p[i],node(8,0,0));
      p[i].hour=8;
      p[i].minite=0;
      p[i].second=0;
    }
  }
  // for(int i=0;i<n;i++)
  // {
  //   printf("%02d:%02d:%02d %d\n",p[i].hour,p[i].minite,p[i].second,p[i].processing);
  // }
  while(index<n)
  {
    if(after(p[index]))
    {
      break;
    }
    int tmp=0,tmptime=vec[0].endtime;
    for(int i=1;i<m;i++)
    {
      if(tmptime>vec[i].endtime)
      {
        tmp=i;
        tmptime=vec[i].endtime;
      }
    }
    if(_time_dif(node(8,0,0),p[index])<tmptime)
    {
      vec[tmp].q.pop();
      vec[tmp].q.push(p[index]);
      wait+=(vec[tmp].endtime-_time_dif(node(8,0,0),p[index]));
      vec[tmp].endtime+=p[index].processing*60;
      // cout<<"END:"<<endl<<vec[tmp].endtime<<endl;
      // cout<<wait<<endl;
    }else
    {
      vec[tmp].q.pop();
      vec[tmp].q.push(p[index]);
      vec[tmp].endtime=p[index].processing*60+_time_dif(node(8,0,0),p[index]);
    }
    index++;
  }
  if(wait==0)
    cout<<"0.0"<<endl;
  else
  printf("%.1f\n",to_decimal(wait)/index);
  return 0;
}
