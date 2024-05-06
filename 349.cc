#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //先把nums1放到 没有重复元素的 ，并且无序的unordered_map里（效率高）
    unordered_set<int> set(nums1.begin(), nums1.end());
    //因为nums2中可能有重复的元素，直接用vector 可能会有重复元素
    unordered_set<int> result;

    for (int i : nums2) {
      //如果set里有，nums2中的元素，直接插入，反正是unordered_map，肯定没有重复
      if (set.find(i) != set.end()) result.insert(i);
    }

    //直接使用vector的构造方法 ———— （it->begin(), it->end()）
    return vector<int>(result.begin(), result.end());
  }
};

int main(void) { return 0; }
