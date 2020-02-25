#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> InsertionSort(vector<int> vec,vector<vector<int>> process)
{
  int preIndex,current;
  for(int i=1;i<vec.size();i++)
  {
    preIndex=i-1;
    current=vec[i];
    while(current<vec[preIndex]&&preIndex>=0)
    {
      vec.erase(vec.begin()+preIndex+1);
      vec.insert(vec.begin()+preIndex,current);
      preIndex--;
    }
    // for(int i=0;i<vec.size();i++)
    // {
    //   cout<<vec[i]<<' ';
    // }
    // cout<<endl;

    process.push_back(vec);
    current=vec[i+1];
  }
  return process;
}

vector<vector<int>> merge_sort(vector<int> vec)
{
  vector<vector<int>> merge_res;
  int n=vec.size();
  for(int i=1;i<2*n;i*=2)
  {
    for(int j=0;j<n/i;j++)
    {
      sort(vec.begin()+i*j,vec.begin()+(j+1)*i);
    }
    sort(vec.begin()+i*(n/i),vec.end());
    merge_res.push_back(vec);
    // for(int i=0;i<vec.size();i++)
    // {
    //   cout<<vec[i]<<' ';
    // }
    // cout<<endl;
  }
  return merge_res;
}

int main()
{
  int n;
  cin>>n;
  vector<int> vec;
  vector<int> mid;
  vector<vector<int>> insert_pro;
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    vec.push_back(tmp);
  }
  for(int i=0;i<n;i++)
  {
    int tmp;
    cin>>tmp;
    mid.push_back(tmp);
  }
  insert_pro=InsertionSort(vec,insert_pro);
  for(int i=0;i<insert_pro.size();i++)
  {
    if(insert_pro[i]==mid)
      {
        cout<<"Insertion Sort"<<endl;
        while (insert_pro[i]==mid) {
          i++;
        }
        for(int j=0;j<insert_pro[i].size()-1;j++)
        {

          cout<<insert_pro[i][j]<<' ';
        }
        cout<<insert_pro[i][n-1]<<endl;
        return 0;
        break;
      }
  }
  vector<vector<int>> merge_res;
  merge_res=merge_sort(vec);
  for(int i=0;i<merge_res.size();i++)
  {
    if(merge_res[i]==mid)
    {
      cout<<"Merge Sort"<<endl;
      for(int j=0;j<merge_res[i+1].size()-1;j++)
      {
        cout<<merge_res[i+1][j]<<' ';
      }
      cout<<merge_res[i+1][n-1]<<endl;
      break;
    }
  }
  return 0;
}
