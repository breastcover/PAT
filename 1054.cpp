#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <iomanip>
using namespace std;

bool legalNumber(string s)
{
  if(s[0]=='-')
  s.erase(s.begin(),s.begin()+1);
  if(s.size()==0)
    return false;
  int point=s.find('.');
  int d=s.size()-point-1;
  if(point==-1)
  {
    for(int i=0;i<s.size();i++)
    {
      if(!isdigit(s[i]))
        return false;
    }
    double t=stod(s);

    if(t>1000)
      return false;
    return true;
  }

  if(point==-1||d>2)
    return false;
  for(int i=point+1;i<s.size();i++)
  {
    if(!isdigit(s[i]))
      return false;
  }
  for(int i=0;i<s.size();i++)
  {
    if(i!=point&&!isdigit(s[i]))
      return false;
  }
  double t=stod(s);
  if(t>1000)
    return false;
  return true;
}

int main()
{
  int n;
  cin>>n;
  string s;
  double sum=0;
  int num=0;
  for(int i=0;i<n;i++)
  {
    cin>>s;
    if(legalNumber(s))
    {
      sum+=stod(s);

      num++;

    }
    else
      cout<<"ERROR: "+s+" is not a legal number"<<endl;
  }

  if(num>1)
  printf("The average of %d numbers is %.2f\n",num,sum/num);
  else if(num==1)
  printf("The average of 1 number is %.2f\n",sum);
  else
  printf("The average of 0 numbers is Undefined\n");
  return 0;
}
