#include <iostream>
#include <string>

#include <algorithm>
#include <cctype>

using namespace std;

bool isGood(char c,string keys)
{
  if(keys.find_first_of('+')!=-1&&c>='A'&&c<='Z')
    return false;
  if(keys.find_first_of('_')!=-1&&c==' ')
    return false;
  if(keys.find_first_of(toupper(c))!=-1)
    return false;
  return true;
}

int main()
{
  string keys;
  string input;
  getline(cin,keys);
  cin>>input;
  string res;
  
  for(int i=0;i<input.size();i++)
  {

    if(isGood(input[i],keys))
    {
      res+=input[i];
    }
  }
  cout<<res<<endl;
  return 0;
}
