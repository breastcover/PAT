#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;



struct _candidate
{
  string _output;
  string _level;
  int _examination_room_number;
  string _date;
  int _number;
  int _score;
};

struct _kc_statistics
{
  int _sum_score=0;
  int _sum_people=0;
  int _examination_room_number;
};

bool cmp_score(_candidate c1,_candidate c2)
{
  if(c1._score==c2._score)
    return c1._output<c2._output;
  return c1._score>c2._score;
}

bool cmp_type3(_kc_statistics k1,_kc_statistics k2)
{
  if(k1._sum_people==k2._sum_people)
    return k1._examination_room_number<k2._examination_room_number;
  return k1._sum_people>k2._sum_people;
}

vector<_candidate> _type_1(vector<_candidate> vec,string _order)
{
  vector<_candidate> res;
  for(_candidate c:vec)
  {
    if(c._level==_order)
      res.push_back(c);
  }
  sort(res.begin(),res.end(),cmp_score);
  return res;
}

vector<_kc_statistics> _type_2(vector<_candidate> vec,string _order)
{
  vector<_kc_statistics> res(1);
  for(_candidate c:vec)
  {
    if(c._examination_room_number==stoi(_order))
    {
      res[0]._sum_score+=c._score;
      res[0]._sum_people++;
    }
  }
  return res;
}

vector<_kc_statistics> _type_3(vector<_candidate> vec,string _order)
{
  map<int,int> m;
  for(_candidate c:vec)
  {
    if(c._date==_order)
    {
      m[c._examination_room_number]++;
    }
  }
  vector<_kc_statistics> res;
  for(auto iter=m.begin();iter!=m.end();iter++)
  {
    _kc_statistics k;
    k._examination_room_number=iter->first;
    k._sum_people=iter->second;
    res.push_back(k);
  }
  sort(res.begin(),res.end(),cmp_type3);
  return res;
}


int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<_candidate> vec(n);
  for(int i=0;i<n;i++)
  {
    string s;
    int tmp;
    cin>>s>>tmp;
    vec[i]._output=s;
    vec[i]._level=s.substr(0,1);
    vec[i]._examination_room_number=stoi(s.substr(1,3));
    vec[i]._date=s.substr(4,6);
    vec[i]._number=stoi(s.substr(11,3));
    vec[i]._score=tmp;
  }
  for(int i=0;i<m;i++)
  {
    string _type,_order;
    cin>>_type>>_order;
    if(_type=="1")
    {
      printf("Case %d: %s %s\n",i+1,_type.c_str(),_order.c_str());
      vector<_candidate> res1=_type_1(vec,_order);
      if(res1.empty())
      {
        cout<<"NA"<<endl;
        continue;
      }

      for(_candidate c:res1)
        //cout<<c._output<<" "<<to_string(c._score)<<endl;
        printf("%s %d\n",c._output.c_str(),c._score );
    }
    else if(_type=="2")
    {
      printf("Case %d: %s %s\n",i+1,_type.c_str(),_order.c_str());
      vector<_kc_statistics> res2=_type_2(vec,_order);
      if(res2[0]._sum_people==0)
      {
        cout<<"NA"<<endl;
        continue;
      }

      //cout<<res2[0]._sum_people<<' '<<res2[0]._sum_score<<endl;
      printf("%d %d\n",res2[0]._sum_people, res2[0]._sum_score);
    }
    else if(_type=="3")
    {
      printf("Case %d: %s %s\n",i+1,_type.c_str(),_order.c_str());
      vector<_kc_statistics> res3=_type_3(vec,_order);
      if(res3.empty())
      {
        cout<<"NA"<<endl;
        continue;
      }

      for(_kc_statistics k:res3)
      {
        //cout<<k._examination_room_number<<' '<<k._sum_people<<endl;
        printf("%d %d\n",k._examination_room_number,k._sum_people );
      }
    }
  }
  return 0;
}
