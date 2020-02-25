#include <iostream>
#include <vector>
#include <utility>
using namespace std;


int n;
long long m;
vector<long long> vec(100100,0);

int binary_search(int st,int ed)
{
  int mid;
  while(st<ed)
  {
    mid=(st+ed)/2;
    if(vec[ed]-vec[mid]>m)
      st=mid+1;
    else if(vec[ed]-vec[mid]<m)
      ed=mid;
    else
      return mid;
  }
  return (st+ed)/2-1;
}


int find(int x, int y){
	int left = x, right = y;
	int mid;
	while(left < right){
//		cout << left << " " << right << endl;
		mid = (left + right) / 2;
		if(vec[y] - vec[mid] < m){
			right = mid;
		}
		else if(vec[y] - vec[mid] > m)
			left = mid + 1;
		else
			return mid;
	}
	return (left + right) / 2 - 1;

}

int main()
{
  cin>>n>>m;
  vec[0]=0;
  for(int i=1;i<=n;i++)
  {
    cin>>vec[i];
    vec[i]+=vec[i-1];
  }
  for(int i=1;i<=n;i++)
  {
    cout<<vec[i]<<' ';
  }
  cout<<endl;
  long long min_dif=1e8;
  vector<pair<int,int>> res;
  for(int i=1;i<=n;i++)
  {
    if(vec[i]>=m)
    {
      int j=find(0,i);
      cout<<j<<endl;

      if(vec[i]-vec[j]-m<min_dif)
      {
        min_dif=vec[i]-vec[j]-m;
        res.clear();
        res.push_back(make_pair(j+1,i));
      }
      else if(vec[i]-vec[j]-m==min_dif)
      {
        res.push_back(make_pair(j+1,i));
      }

    }
  }
  for(auto iter=res.begin();iter!=res.end();iter++)
  {
    cout<<iter->first<<'-'<<iter->second<<endl;
  }
  return 0;
}
