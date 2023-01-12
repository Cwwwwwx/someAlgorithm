/**
 * 142.环形链表II
 * 首先用快慢指针来确定链表是否成环，快指针一次走两步，慢指针一次走一步
 * 步长每回增加1，所以如果是环形链表一定会相遇，环形长度不变
 * 设x为头节点到入口长度，y为入口长度到相遇节点长度，z为剩余环形长度
 * 相遇前慢节点走过的距离为x+y，快指针为x+y+n(y+z)
 * (x + y)*2 = x + y + n(y + z)
 * 整理后可得 x = (n - 1)(y + z) + z
 * 解释为 n = 0时 x = z，设置index1为头节点位置，index2为相遇节点位置，同时每次走一步，相遇位置为入口点
 * n ！= 0时说明快指针在环形链表内多循环了n - 1次后相遇
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastptr = head;
        ListNode* slowptr = head;  
        while (fastptr != nullptr && fastptr->next != nullptr) //这里判断条件，因为循环中执行的是fastptr = fastptr->next->next，所以要判断两个结尾指针是否为空
        {
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
            if (fastptr == slowptr)
            {
                ListNode* index1 = head;
                ListNode* index2 = fastptr;
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};