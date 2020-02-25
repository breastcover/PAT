#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;


bool mydigit(char a) {
	return !(isdigit(a) || a == '.');
}
bool isLegal(string s) {
	int point = count(s.begin(),s.end(),'.');		//记录小数点
	int m = 0;		//记录小数位数
	if (s.find('.') != string::npos) m = s.length() - s.find('.') - 1;
	if (!(s[0] == '-'&&s.length()>1) && !isdigit(s[0]))			//第一位必为数字或者负号（不能只有负号）
		return 0;
	if (m <= 2 && fabs(stof(s)) <= 1000 && find_if(s.begin()+1, s.end(), mydigit) == s.end())			//必须保证在题目范围内
		return 1;
	return 0;

}

int main()
{
  int n;
  cin>>n;
  string s;
  double sum=0;
  double num=0;
  while(n--)
  {
    cin>>s;
    if(isLegal(s))
    {
      sum=sum+stof(s.c_str());
      num++;
    }
    else
      cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
  }
  if(num>1)
  printf("The average of %.f numbers is %.2f\n",num,sum/num);
  else if(num==1)
  printf("The average of 1 number is %.2f\n",sum);
  else
  printf("The average of 0 numbers is Undefined\n");
  return 0;
}
