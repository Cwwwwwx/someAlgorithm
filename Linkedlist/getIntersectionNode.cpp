/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * ������ 02.07. �����ཻhttps://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
 * �������Ҫ�ж���������β�˲����Ƿ���ͬ��Ҫ��ĩβ���롣�����ͬ�ҳ���һ����ͬ�������ַ���أ����򷵻�NULL
 * 
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;
        int sizeA = 0;
        int sizeB = 0;
        while (A != NULL) //����A ��= null����Ա������������������null����
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

/*���ǹ��������ڵ�ָ�� A? , B �ֱ�ָ��������ͷ�ڵ� headA , headB �������²�����
ָ�� A �ȱ��������� headA ���ٿ�ʼ�������� headB �����ߵ� node ʱ�����߲���Ϊ��
a + (b - c)
ָ�� B �ȱ��������� headB ���ٿ�ʼ�������� headA �����ߵ� node ʱ�����߲���Ϊ��
b + (a - c)
����ʽ��ʾ����ʱָ�� A , B �غϣ��������������
a + (b - c) = b + (a - c)
�������� �� ����β�� (�� c > 0c>0 ) ��ָ�� A , B ͬʱָ�򡸵�һ�������ڵ㡹node ��
�������� �� ����β�� (�� c = 0c=0 ) ��ָ�� A , B ͬʱָ�� nullnull ��
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