#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int n;
  string s;
  vector<string> vec;
  int rest=0;
  cin>>n>>s;
  string str=s;
  vec.push_back(s);
  int p=1;
  n=n-p;
  //cout<<1<<endl;
  while(n)
  {
    str=str+s+s;
    p+=2;
    if(n>=2*p)
      n=n-2*p;
    else
    {
      rest=n;
      n=0;
      break;
    }
    //cout<<str<<endl;
    vec.insert(vec.begin(),str);
    vec.push_back(str);


  }
  string s1="";
  for(int i=0;i<vec.size();i++)
  {
    cout<<s1;
    cout<<vec[i]<<endl;
    if(i<=vec.size()/2-1)
      s1=s1+" ";
    else
      s1=s1.substr(0,s1.size()-1);

  }
  if(rest>0)
    cout<<rest<<endl;
  return 0;
}
