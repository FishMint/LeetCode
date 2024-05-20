#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

<<<<<<< HEAD
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
=======
struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *listA, *listB;

        //计算A，B的长度
        for(listA = headA; listA != NULL; listA = listA->next) lenA++;
        for(listB = headB; listB != NULL; listB = listB->next) lenB++;
        
        //让A始终是最长的
        if(lenA < lenB) {
            swap(headA, headB);
            swap(lenA, lenB);
        } 

        listA = headA;
        listB = headB;

        for(int i = 0; i < lenA - lenB; i++) listA = listA->next;

        while (listA != listB) {
            if(listA == NULL || listB == NULL)  return NULL;
            listA = listA->next;
            listB = listB->next;
        }

        return listA;
>>>>>>> 6b61c29d39cf6237e5c78ace60248bf0d9e4795d
    }
};

int main()

{
    
    return 0;
}
