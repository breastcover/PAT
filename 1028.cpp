#include <iostream>
#include <string>
#include <map>
using namespace std;

bool compare(string s1,string s2)
{
  if(s1>s2)
  return true;
  else
  return false;
}

int main()
{
    int n;
    cin>>n;
    string name,date;
    string max_date="";
    string min_date="2014/9/6";
    string max_name,min_name;
    map<string,string> m;
    for(int i=0;i<n;i++)
    {
      cin>>name>>date;
      if(date>="1814/09/06"&&date<="2014/09/06")
      {
        m[name]=date;
        if(date>max_date)
        {
          max_name=name;
          max_date=date;
        }
        if(date<min_date)
        {
          min_date=date;
          min_name=name;
        }
      }
    }
    if(m.size()==0)
    {
      min_name="0";
      max_name="0";
    }
    cout<<m.size()<<' '<<min_name<<' '<<max_name<<endl;
    return 0;
}
