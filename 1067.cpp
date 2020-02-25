#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
  string s;
  int n;
  cin>>s>>n;
  string password;
  int times=0;
  getchar();
  while(getline(cin,password))
  {

    times++;
    if(times>n)
    {
      cout<<"Account locked"<<endl;
      break;
    }
    else if(password=="#")
      break;
    else if(password==s)
    {
      cout<<"Welcome in"<<endl;
      break;
    }
    else
    {
      cout<<"Wrong password: "<<password<<endl;
    }

  }
  return 0;
}
