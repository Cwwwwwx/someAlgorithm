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

    int get(int index) //index指向头节点
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

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
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

    ListNode* reverseList(ListNode* head) //翻转链表
    {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* tem;
        while(cur)
        {
            tem = cur;
            cur = cur->next;    //cur要先去下一段，不然会随着tem改变而改变，因为所指域空间相同        
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