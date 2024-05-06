#include<iostream>
#include<string>

struct ListNode {
     int val;
     ListNode *next;
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		int len = 0;
		ListNode *cur =head, *v_head = new ListNode;

		//来一个虚头节点
		v_head->next = head;

		//开始统计一下总长度
		while(cur != NULL){
			len++;
			cur = cur->next;
		}

		//差值
		len = len - n;
		//重置一下节点
		ListNode *pre = v_head;
		cur = head;

		//因为虚头节点的原因，pre一直是要删除的点前面的那个
		while(len--){
			pre = pre->next;
			cur = cur->next;
		}
		
		//直接把中间的那个删除前接上后，最后返回虚头节点的后面那个就好了
		pre->next = cur->next;
		delete(cur);
		return v_head->next;
    }
};


int main(){
	return 0;
}
