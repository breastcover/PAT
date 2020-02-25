#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

string diwei[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string gaowei[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string to_hx(string number)
{
  string res;
  int d=stoi(number);

  if(d>13)
  {
    res=gaowei[d/13];
    if(d%13!=0)
      res=res+' '+diwei[d%13];
  }
  else if(d==13)
    return "tam";
  else
    res=diwei[d];

    return res;
}

string to_sz(string number)
{
  if(number.size()>4)
  {
    string s1=number.substr(0,3);

    string s2=number.substr(4);
    //cout<<s1<<" "<<s2<<endl;
    int g,d;
    for(int i=0;i<13;i++)
    {
      if(s1==gaowei[i])
        g=i;
      if(s2==diwei[i])
        d=i;
    }
    int tmp=g*13+d;
    return to_string(tmp);
  }
  else
  {


    for(int i=0;i<13;i++)
    {
      if(number==diwei[i])
        return to_string(i);
      else if(number==gaowei[i])
        return to_string(i*13);
    }
  }
}

int main()
{
  int n;
  cin>>n;
  string s;
  vector<string> vec(n);
  getchar();
  for(int i=0;i<n;i++)
  {
    getline(cin,vec[i]);
  }
  for(int i=0;i<n;i++)
  {

    if(isalpha(vec[i][0]))
      {cout<<to_sz(vec[i])<<endl;continue;}
    cout<<to_hx(vec[i])<<endl;
  }
  return 0;

}
