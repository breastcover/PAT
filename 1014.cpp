#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

const string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main()
{
    string s;
    vector<string> vec;
    for(int i=0;i<4;i++)
    {
        cin>>s;
        vec.push_back(s);
    }
    int flag=0;
    for(int i=0;i<vec[0].size();i++)
    {
      if(vec[0][i]==vec[1][i]&&vec[0][i]>='A'&&vec[0][i]<='G')
      {
        if(flag==0)
        {
        flag=i;
        int p=vec[0][i]-'A';
        cout<<week[p]<<" ";
        break;
        }
      }
    }
    for(int i=flag+1;i<vec[0].size();i++)
    {
      if(vec[0][i]==vec[1][i]&&vec[0][i]>='0'&&vec[0][i]<='9')
      {
        int p=vec[0][i]-'0';
        cout<<"0";
        cout<<to_string(p)<<":";
        break;
      }
      else if(vec[0][i]==vec[1][i]&&vec[0][i]>='A'&&vec[0][i]<='N')
      {
        int p=vec[0][i]-'A';
        cout<<to_string(p+10)<<":";
        break;
      }
    }

    for(int i=0;i<vec[2].size();i++)
    {
        if(vec[2][i]==vec[3][i]&&isalpha(vec[2][i]))
        {
           if(i<10)
                cout<<"0",cout<<i;

            else
                cout<<i;
        }
    }
    return 0;
}
