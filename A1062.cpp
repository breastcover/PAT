#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct people
{
  string ID_Number;
  int Virtue_Grade;
  int Talent_Grade;
  int Total;
}P;

bool cmp(people p1,people p2)
{
  if(p1.Total==p2.Total)
  {
    if(p1.Virtue_Grade==p2.Virtue_Grade)
    {
      if(p1.Talent_Grade==p2.Talent_Grade)
        return p1.ID_Number<p2.ID_Number;
    }
    return p1.Virtue_Grade>p2.Virtue_Grade;
  }
  return p1.Total>p2.Total;
}

int main()
{
  int n,l,h;
  cin>>n>>l>>h;
  vector<people> sages;
  vector<people> noblemen;
  vector<people> foolmen;
  vector<people> rest;
  for(int i=0;i<n;i++)
  {
    cin>>P.ID_Number>>P.Virtue_Grade>>P.Talent_Grade;
    P.Total=P.Virtue_Grade+P.Talent_Grade;
    if(P.Virtue_Grade>=h&&P.Talent_Grade>=h)
      sages.push_back(P);
    else if(P.Virtue_Grade>=h&&P.Talent_Grade>=l)
      noblemen.push_back(P);
    else if(P.Virtue_Grade>=l&&P.Talent_Grade>=l&&P.Virtue_Grade>=P.Talent_Grade)
      foolmen.push_back(P);
    else if(P.Virtue_Grade>=l&&P.Talent_Grade>=l)
      rest.push_back(P);
  }
  sort(sages.begin(),sages.end(),cmp);
  sort(noblemen.begin(),noblemen.end(),cmp);
  sort(foolmen.begin(),foolmen.end(),cmp);
  sort(rest.begin(),rest.end(),cmp);
  cout<<sages.size()+noblemen.size()+foolmen.size()+rest.size()<<endl;
  for(int i=0;i<sages.size();i++)
  {
    cout<<sages[i].ID_Number<<" "<<sages[i].Virtue_Grade<<' '<<sages[i].Talent_Grade<<endl;
  }
  for(int i=0;i<noblemen.size();i++)
  {
    cout<<noblemen[i].ID_Number<<" "<<noblemen[i].Virtue_Grade<<' '<<noblemen[i].Talent_Grade<<endl;
  }
  for(int i=0;i<foolmen.size();i++)
  {
    cout<<foolmen[i].ID_Number<<" "<<foolmen[i].Virtue_Grade<<' '<<foolmen[i].Talent_Grade<<endl;
  }
  for(int i=0;i<rest.size();i++)
  {
    cout<<rest[i].ID_Number<<" "<<rest[i].Virtue_Grade<<' '<<rest[i].Talent_Grade<<endl;
  }
  return 0;
}
