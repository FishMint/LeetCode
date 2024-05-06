#include <iostream>
#include <string>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    //看看有没有环，有环内部处理，没有返回NULL
    while (fast != NULL && fast->next != NULL) {
      //开始移动
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow) {
        slow = head;
        while (fast != slow) {
          fast = fast->next;
          slow = slow->next;
        }
        return fast;
      }
    }

    return NULL;
  }
};

int main(void) { return 0; }
