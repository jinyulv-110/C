#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main()
{
  int n;
  int k;
  cin>>n>>k;
  vector<int> nums(n);
  for(int i=0;i<n;++i)
  {
    cin>>nums[i];
  }
  sort(nums.begin(),nums.end());
  nums.erase(unique(nums.begin(),nums.end()),nums.end());
  vector<int> selected;
  for(int i=0;i<k;++i)
  {
    selected.push_back(nums[i]);
  }
  int m=0;
  for(int i=0;i<k;++i)
  {
    if(m!=selected[i])
    {
      cout<<m;
      return 0;
    }
    m++;
  }
  cout<<k<<endl;
  return 0;
}
