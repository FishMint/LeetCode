#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
        int lenth = nums.size(), left, right, sum = 0;
		vector<vector<int>> ans;

        for(int i = 0; i <= (lenth - 1) - 3; i++){				//第一个数字
			if(i > 0 && nums[i] == nums[i - 1]) continue;		//第一个数字去重
			if((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)	break;								//最小组合大于0
			if((long long)nums[i] + nums[lenth - 1 - 2] + nums[lenth - 1 - 1] + nums[lenth - 1] < target)	continue;		//最大的组合小于0 

			//最后一个数字
			for(int j = lenth -1; j > i + 2; j--){
				if(j < lenth -1 && nums[j] == nums[j + 1])	continue;						//最后一个数字的去重
				if((long long)nums[i] + nums[j - 2] + nums[j - 1] + nums[j] < target)	break;			//最小组合大于0
				if((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[j] > target)	continue;		//最小的组合大于0 

				//确认第2，3个数
				left = i + 1;
				right = j - 1;

				while(left < right){
					sum = nums[i] + nums[left] + nums[right] + nums[j];
					if(sum > target)	right--;
					else if(sum < target)	left++;
					else {
						ans.push_back(vector<int>{ nums[i], nums[left],
												   nums[right], nums[j]});

						//开始去重（中间两个）
						while(left < right && nums[left] == nums[left + 1])		left++;
						while(left < right && nums[right] == nums[right - 1])	right--;
						left++;
						right--;
					}
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
