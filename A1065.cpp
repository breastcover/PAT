#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long res=a+b;
        bool flag=true;
        if(a>0&&b>0&&res<=0)
          flag=true;
        else if(a<0&&b<0&&res>=0)
          flag=false;
        else if(res<=c)
          flag=false;
        if(flag)
        {
            cout<<"Case #"<<i+1<<": true"<<endl;
        }
        else
            cout<<"Case #"<<i+1<<": false"<<endl;
    }
    return 0;
}
