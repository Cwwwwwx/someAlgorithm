#include <iostream>
using namespace std;

//19.ɾ������ĵ�����N���ڵ�
//˫������ ��ָ������n+1����Ȼ�����ָ��ͬʱ�ߣ�ֱ����ָ��Ϊnull
//�൱����ָ�����ָ��Ҫɾ����λ��
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

        //�ͷ��ڴ�
        delete tem;
        return dummyHead->next;
    }
};