#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  string illegal[m];
  for(int i=0;i<m;i++)
    cin>>illegal[i];
  int p_num=0,illegal_goods_num=0;
  for(int i=0;i<n;i++){
    string name;
    cin>>name;
    string goods;
    char c;
    int flag=0;
    while(cin>>goods){
      for(int j=0;j<m;j++){
        if(goods==illegal[j]){
          if(flag==0){
            p_num++;
            cout<<name<<":";
            flag=1;
          }
          cout<<" "<<goods;
          illegal_goods_num++;
        }
      }
      if (getchar() == '\n')
		    break;
    }
    if(flag==1)
    cout<<endl;
  }
  cout<<p_num<<' '<<illegal_goods_num<<endl;
  return 0;
}
