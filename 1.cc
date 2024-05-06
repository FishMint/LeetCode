#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> n_map;

    for (int idx = 0; idx < nums.size(); idx++) {
      //如果找得到的话就直接返回
      if (n_map.find(target - nums[idx]) != n_map.end())
        return {idx, n_map[target - nums[idx]]};

      //插入当前的数字和下标
      n_map.insert(pair<int, int>(nums[idx], idx));
    }

	//找不到就返回空
    return {};
  }
};

int main(void) { return 0; }
