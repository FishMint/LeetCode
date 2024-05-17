#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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
    }
};

int main()

{
    
    return 0;
}
