#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> map1_2;
    int target = 0, result = 0;

    //计算nums 1，2的和
    for (int a : nums1) {
      for (int b : nums2) {
        map1_2[a + b]++;
      }
    }

    for (int c : nums3) {
      for (int d : nums4) {
        target = -c - d;
        if (map1_2.find(target) != map1_2.end()) result += map1_2[target];
      }
    }

    return result;
  }
};

int main(void) { 

	vector<int> nums1 ={1,2 };
	vector<int> nums2 ={-2,-1 };
	vector<int> nums3 ={-1,2 };
	vector<int> nums4 ={0,2 };
	Solution s;
	s.fourSumCount(nums1,nums2,nums3,nums4);
	return 0; }
