#include <iostream>
using namespace std;

//19.删除链表的倒数第N个节点
//双链表法， 快指针先走n+1步，然后和慢指针同时走，直到快指针为null
//相当于慢指针最后指向要删除的位置
class Solution {
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };   
    
    ListNode* removeNthFromEnd (ListNode* head, int n)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slowptr = dummyHead;
        ListNode* fastptr = dummyHead;
        while (n--)
        {
            fastptr = fastptr->next;
        }
        fastptr = fastptr->next;

        while (fastptr != nullptr)
        {
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }

        ListNode* tem = slowptr->next;
        slowptr->next = tem->next;

        //释放内存
        delete tem;
        return dummyHead->next;
    }
};