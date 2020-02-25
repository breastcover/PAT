#include <iostream>
#include <map>
using namespace std;

int game(char ch1,char ch2)
{
   switch (ch1)
   {
   case  'C':
    {
        if(ch2=='C')
            return 0;
        else if(ch2=='J')
            return 1;
        else if(ch2=='B')
            return -1;
        break;
    }
   case  'J':
    {
        if(ch2=='J')
            return 0;
        else if(ch2=='C')
            return -1;
        else if(ch2=='B')
            return 1;
            break;
    }
    case 'B':
    {
        if(ch2=='B')
            return 0;
        else if(ch2=='C')
            return 1;
        else if(ch2=='J')
            return -1;
            break;
    }
   }
   return 1;

}



int main()
{
    int j_win_num=0,j_lose_num=0,j_draw_num=0;
    map<char,int> j;
    map<char,int> y;
    int n;
    cin>>n;
    char  ch1,ch2;
    while(n--)
    {
        cin>>ch1>>ch2;
        if(game(ch1,ch2)==0)
            j_draw_num++;
        else if(game(ch1,ch2)==1)
            {
                j_win_num++;
                j[ch1]++;
            }
        else
            {
                j_lose_num++;
                y[ch2]++;
            }
    }
    cout<<j_win_num<<' '<<j_draw_num<<' '<<j_lose_num<<endl;
    cout<<j_lose_num<<' '<<j_draw_num<<' '<<j_win_num<<endl;
    int t;
    int MAX=j['C']>(t=j['J']>j['B']?j['J']:j['B'])?j['C']:t;
    for(auto iter=j.begin();iter!=j.end();iter++)
    {
        if(iter->second==MAX)
        {
            cout<<iter->first<<' ';
            break;
        }

    }
    MAX=y['C']>(t=y['J']>y['B']?y['J']:y['B'])?y['C']:t;
    for(auto iter=y.begin();iter!=y.end();iter++)
    {
      if(iter->second==MAX)
      {
          cout<<iter->first<<endl;
          break;
      }
    }

    return 0;
}
