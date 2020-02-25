#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

bool _modify(string& s)
{
  int flag=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='1')
    {
      s[i]='@';
      flag=1;
    }else if(s[i]=='0')
    {
      s[i]='%';
      flag=1;
    }else if(s[i]=='l')
    {
      s[i]='L';
      flag=1;
    }else if(s[i]=='O')
    {
      s[i]='o';
      flag=1;
    }
  }
  if(flag)
    return true;
  return false;
}

struct Node{
  string account;
  string password;
};

int main()
{
  int n;
  cin>>n;
  vector<Node> vec;
  for(int i=0;i<n;i++)
  {
    Node node;
    cin>>node.account>>node.password;
    if(_modify(node.password))
      vec.push_back(node);
  }
  if(vec.size()>0)
  {
    cout<<vec.size()<<endl;
    for(int i=0;i<vec.size();i++)
    {
      cout<<vec[i].account<<' '<<vec[i].password<<endl;
    }
  }
  else if(n==1)
    cout<<"There is "<<n<<" account and no account is modified"<<endl;
  else
    cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
  return 0;
}
