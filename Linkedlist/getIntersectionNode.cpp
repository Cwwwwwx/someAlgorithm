/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 面试题 02.07. 链表相交https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 * 这道题主要判断两个链表尾端部分是否相同，要先末尾对齐。如果相同找出第一个相同的链表地址返回，否则返回NULL
 * 
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;
        int sizeA = 0;
        int sizeB = 0;
        while (A != NULL) //这里A ！= null则可以遍历完整链表不包括最后null部分
        {
            A = A->next;
            sizeA++;
        }

        while (B != NULL)
        {
            B = B->next;
            sizeB++;
        }

        A  = headA;
        B = headB;

        if (sizeA < sizeB)
        {
            swap(sizeA, sizeB);
            swap(A, B);
        }

        int gap = sizeA - sizeB;
        while (gap--)
        {
            A = A->next;
        }

        while(A != NULL)
        {
            if (A == B)
            {
                return A;               
            }
            A = A->next;
            B = B->next;
        }
        return NULL;
    }

/*考虑构建两个节点指针 A? , B 分别指向两链表头节点 headA , headB ，做如下操作：
指针 A 先遍历完链表 headA ，再开始遍历链表 headB ，当走到 node 时，共走步数为：
a + (b - c)
指针 B 先遍历完链表 headB ，再开始遍历链表 headA ，当走到 node 时，共走步数为：
b + (a - c)
如下式所示，此时指针 A , B 重合，并有两种情况：
a + (b - c) = b + (a - c)
若两链表 有 公共尾部 (即 c > 0c>0 ) ：指针 A , B 同时指向「第一个公共节点」node 。
若两链表 无 公共尾部 (即 c = 0c=0 ) ：指针 A , B 同时指向 nullnull 。
*/
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) 
    {
        ListNode* A = headA;
        ListNode* B = headB;
        while (A != B)
        {
            A = A != nullptr ? A->next : headB;
            B = B != nullptr ? B->next : headA;
        }
        return A;
    }   
};