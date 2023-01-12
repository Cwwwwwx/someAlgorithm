#include <iostream>
using namespace std;

class MyLinkedList{
public:    
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };   

    MyLinkedList() 
    {
        _dummyHead = new ListNode(0);
        _size = 0;
    } 

    int get(int index) //indexָ��ͷ�ڵ�
    {
        if (index > _size - 1 || index < 0)
        {
            return -1;
        }
        ListNode* cur = _dummyHead->next;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead (int val)
    {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    void addAtTail (int val)
    {
        ListNode* cur = _dummyHead;
        ListNode* newNode = new ListNode(val);
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // �ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
    // ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
    // ���index��������ĳ��ȣ��򷵻ؿ�
    // ���indexС��0������ͷ������ڵ�
    void addAtIndex (int index, int val)
    {
        if (index > _size - 1)
        {
            return;
        }
        if (index < 0) index = 0;
        ListNode* cur = _dummyHead;
        ListNode* newNode = new ListNode(val);
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    void deleteAtIndex (int index)
    {
        if (index > _size - 1 || index < 0) return;
        ListNode* cur = _dummyHead;
        ListNode* tem;
        while(index--)
        {
            cur = cur->next;
        }
        tem = cur->next;
        cur->next = cur->next->next;
        delete tem;
    }

    void printLinkedList()
    {
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr)
        {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    ListNode* reverseList(ListNode* head) //��ת����
    {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* tem;
        while(cur)
        {
            tem = cur;
            cur = cur->next;    //curҪ��ȥ��һ�Σ���Ȼ������tem�ı���ı䣬��Ϊ��ָ��ռ���ͬ        
            tem->next = pre;    
            pre = tem;
        }
        return pre;
    }    

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

public:
    int _size;
    ListNode* _dummyHead;
};

int main ()
{   
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtTail(4);
    linkedList.printLinkedList();
    linkedList.reverseList(linkedList._dummyHead);
    linkedList.printLinkedList();
}