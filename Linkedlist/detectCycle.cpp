/**
 * 142.��������II
 * �����ÿ���ָ����ȷ�������Ƿ�ɻ�����ָ��һ������������ָ��һ����һ��
 * ����ÿ������1����������ǻ�������һ�������������γ��Ȳ���
 * ��xΪͷ�ڵ㵽��ڳ��ȣ�yΪ��ڳ��ȵ������ڵ㳤�ȣ�zΪʣ�໷�γ���
 * ����ǰ���ڵ��߹��ľ���Ϊx+y����ָ��Ϊx+y+n(y+z)
 * (x + y)*2 = x + y + n(y + z)
 * �����ɵ� x = (n - 1)(y + z) + z
 * ����Ϊ n = 0ʱ x = z������index1Ϊͷ�ڵ�λ�ã�index2Ϊ�����ڵ�λ�ã�ͬʱÿ����һ��������λ��Ϊ��ڵ�
 * n ��= 0ʱ˵����ָ���ڻ��������ڶ�ѭ����n - 1�κ�����
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastptr = head;
        ListNode* slowptr = head;  
        while (fastptr != nullptr && fastptr->next != nullptr) //�����ж���������Ϊѭ����ִ�е���fastptr = fastptr->next->next������Ҫ�ж�������βָ���Ƿ�Ϊ��
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