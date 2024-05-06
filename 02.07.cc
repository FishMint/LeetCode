#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int Len_A = 0, Len_B = 0, Diff;
    ListNode *curA = headA, *curB = headB;

    //计算节点个数
    while (curA != NULL) {
      Len_A++;
      curA = curA->next;
    }
    while (curB != NULL) {
      Len_B++;
      curB = curB->next;
    }

	//保证永远是A长于B
	curA = headA;
	curB = headB;
    if (Len_A < Len_B) {
		std::swap(curA, curB);
		std::swap(Len_A, Len_B);
    }
    Diff = Len_A - Len_B;

	//和B对齐
	while(Diff--){
		curA = curA->next;	
	}

	//看看A和B有没有重叠的地方
	while(curA != curB){
		curA=curA->next;	
		curB= curB->next;
	}

    return curA;
  }
};

int main() {
  Solution s;
  return 0;
}
