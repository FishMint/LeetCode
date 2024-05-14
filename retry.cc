#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // 双指针法
    int removeElement(vector<int> &nums, int val)
    {
        int slow = 0, fast = 0;

        for(; fast < nums.size(); fast++) {
            if(nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;

    }
};

int main()
{
    
    return 0;
}
