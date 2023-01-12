//24. 两两交换链表中的节点
#include <iostream>
using namespace std;

class Solution {
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };   

    ListNode* swapPairs (ListNode* head)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* tem = cur->next;
            ListNode* tem1 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tem;
            cur->next->next->next = tem1;

            cur = cur->next->next;            
        }
        return dummyHead->next;
    }
};
