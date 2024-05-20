#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int i = 0;
		vector<vector<int>> ans;

		//先排序一次,默认升序
		sort(nums.begin(), nums.end());

		for(; i < nums.size() - 2; i++) {
			if(i > 0 && nums[i] == nums[i - 1]) continue;
			int t = -nums[i],
				left = i + 1,
				right = nums.size() - 1;

			while(left < right) {
				int sum = nums[left] + nums[right];
				if(t == sum) {
					ans.push_back({nums[i], nums[left], nums[right]});
					while(left < right && nums[left] == nums[left + 1]) 
						left++;
					while(left < right && nums[right] == nums[right - 1]) 
						right--;
					left++;
					right--;
				}else if(t < sum) {
					right--;
				}else {
					left++;
				}
			}
		}
		return ans;
    }
};

int main()
{
    
    return 0;
}
