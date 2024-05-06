#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
不使用哈希  (timeout)
直接使用滑动窗口
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		int left , right, sum, lenth = nums.size();
		vector<vector<int>> ans;
		
        //确定第一个数字
		for (int i = 0; i < lenth - 2; i++) {
			//因为是升序,最小的都大于0了,那肯定是没有结果的
			//如果和前面一个有重复，那就直接跳过
			if(nums[i] > 0)	break;	
			else if(i > 0 && nums[i] == nums[i - 1]) continue;

			left = i + 1;	
			right = lenth - 1;

			while(left < right){
				sum = nums[left] + nums[right];		//计算和

				if(sum > -nums[i])	right--;	//大的话右边向左移动
				else if(sum < -nums[i])	left++;		
				else{
					ans.push_back( vector<int> {nums[i], 
												nums[left], 
												nums[right]});

					while(nums[right] == nums[right - 1] && left < right)	right--;
					while(nums[left] == nums[left + 1] && left < right)		left++;
					left++;
					right--;
				}
			}
		}

		return ans;
	}

};

int main(void) { return 0;}
