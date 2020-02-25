#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct car
{
  string id;
  string in_time;
  string out_time;
  string status;
  int last_time;
  bool in;
  bool out;
  bool valid;
};

struct node
{
  string s;
  int num;
};

int D_value(car c1)
{
  int in_h=stoi(c1.in_time.substr(0,2));
  int in_m=stoi(c1.in_time.substr(3,2));
  int in_s=stoi(c1.in_time.substr(6,2));
  int out_h=stoi(c1.out_time.substr(0,2));
  int out_m=stoi(c1.out_time.substr(3,2));
  int out_s=stoi(c1.out_time.substr(6,2));
  return out_h*3600+out_m*60+out_s-in_h*3600-in_m*60-in_s;
}

bool cmp(car c1,car c2)
{
  return c1.in_time<c2.in_time;
}

vector<car> vec;
vector<node> cars_num;

int bisearch(string s,int l,int r)
{
  while(l<r)
  {
    int mid=(l+r)/2;
    if(cars_num[mid].s>s)
    {
      r=mid;
    }else if(cars_num[mid].s<=s)
    {
      l=mid+1;
    }
  }
  return l;
}

bool cmp_init(car c1,car c2)
{
  if(c1.id==c2.id)
    return c1.in_time<c2.in_time;
  else
    return c1.id<c2.id;
}

int main()
{
  int n,k;
  cin>>n>>k;
  vector<car> init(n);
  for(int i=0;i<n;i++)
  {
    cin>>init[i].id>>init[i].in_time>>init[i].status;
  }
  sort(init.begin(),init.end(),cmp_init);
  // cout<<"************"<<endl;
  // for(auto e:init)
  // {
  //   cout<<e.id<<' '<<e.in_time<<' '<<e.status<<endl;
  // }
  map<string,car> m;
  vector<car> out;
  car pre;
  for(int i=0;i<n;i++)
  {
    car c=init[i];
    m[c.id].id=c.id;
    if(c.status=="in")
    {
      m[c.id].in_time=c.in_time;
      m[c.id].in=true;
      pre=c;
    }
    else if(c.status=="out")
    {
      if(m[c.id].in==true)
      {
        m[c.id].out_time=c.in_time;
        m[c.id].last_time+=D_value(m[c.id]);
        m[c.id].in=false;
        out.push_back(pre);
        out.push_back(c);
      }
    }
  }
  vector<string> res;
  int MAX_time=-1;
  for(auto iter=m.begin();iter!=m.end();iter++)
  {

    if(iter->second.last_time>MAX_time)
    {
      MAX_time=iter->second.last_time;
      res.clear();
      res.push_back(iter->first);
    }
    else if(iter->second.last_time==MAX_time)
    {
      res.push_back(iter->first);
    }
    vec.push_back(iter->second);

  }
  sort(out.begin(),out.end(),cmp);
  // cout<<"*********"<<endl;

  int all_num=0;
  for(auto e:out)
  {
    node Node;
    Node.s=e.in_time;
    if(e.status=="in")
      Node.num=(++all_num);
    else
      Node.num=(--all_num);
    cars_num.push_back(Node);
  }
  // for(auto e:cars_num)
  // {
  //   cout<<e.s<<' '<<e.num<<endl;
  // }
  for(int i=0;i<k;i++)
  {
    string s;
    cin>>s;
    int l=bisearch(s,0,cars_num.size());
    cout<<cars_num[l-1].num<<endl;
  }
  for(int i=0;i<res.size();i++)
  {
    cout<<res[i]<<' ';
  }
  printf("%02d:%02d:%02d\n",MAX_time/3600,MAX_time%3600/60,MAX_time%60);
  return 0;
}
