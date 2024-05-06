#include<iostream>
#include<string>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(head == NULL)	return NULL;

		//定义前中后指针
		ListNode *pre = NULL, *cur = head, *after;

		//备份cur后指针
		//把cur 的next -> pre
		//再把pre向后面移动（就是cur）
		//cur也向后移动，就是after备份指针的位置
		//然后重复运行
		while(cur != NULL){
			after = cur->next;
			cur->next = pre;
			pre = cur;
			cur = after;
		}

		//退出的时候，cur肯定是NULL，pre一定是最后一个，反转后的第一个
		return pre;
    }
};

int main(){
	return 0;
}
