#include <iostream>
#include <string>
using namespace std;

string to_Mars_color(int n)
{
  string res;
  if(n==0)
    res="00";
  while(n)
  {
    int tmp=n%13;
    if(tmp>=10)
    {
      char c=(tmp-10)+'A';
      res=c+res;
    }
    else
      res=to_string(tmp)+res;
    n/=13;
  }
  if(res.size()==1)
    res="0"+res;
  return res;
}

int main()
{
  int r,g,b;
  cin>>r>>g>>b;
  string res='#'+to_Mars_color(r)+to_Mars_color(g)+to_Mars_color(b);
  cout<<res<<endl;
  return 0;
}
