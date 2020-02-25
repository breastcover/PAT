#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  string s1,s2;
  getline(cin,s1);
  getline(cin,s2);
  bool hashmap[128]={false};
  for(int i=0;i<s2.size();i++)
    hashmap[s2[i]]=true;
  for(int i=0;i<s1.size();i++)
  {
    if(hashmap[s1[i]]==false)
      cout<<s1[i];
  }
  return 0;
}
