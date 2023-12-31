/*
Author: CagurZhan
Description: 设计链表，实现实现头插法、尾插法、中间插入法、删除
*/
#include <iostream>
using namespace std;
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

// 采用虚拟头结点方式设计一个单链表
class MyLinkedList {

public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val, ListNode*next) : val(val),next(next){}        
    };
private:
    int _size;
    ListNode * dummyHead;

public:
    MyLinkedList() {
        dummyHead = new ListNode(0,nullptr);
        _size = 0;
    }
    
    int get(int index) {
        // 判断
        if(index >= _size || index < 0) return -1;

        // size = 2, index = 1
        ListNode* p = dummyHead;
        while(index--){
            p = p->next;
        }
        // p-> 第二个结点
        
        return p->next->val;
    }
     
    void addAtHead(int val) {
        ListNode * node = new ListNode(val,dummyHead->next);
        dummyHead->next = node;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* p = dummyHead;
        while(p->next!=nullptr) p = p->next;
        ListNode* node = new ListNode(val,nullptr);
        p->next = node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size) return ;
        if(index < 0 ) index = 0;

        ListNode*p = dummyHead;

        while(index --){
            p = p->next;
        }
        ListNode* node = new ListNode(val,p->next);
        p->next = node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=_size || index<0)return ;
        ListNode *p = dummyHead;
        while(index--){
            p = p->next;
        }
        ListNode* t = p->next;
        p->next = p->next->next;
        delete t;
        t = nullptr;
        _size--;
    }
    void printLinkedList() {
        ListNode* cur = dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};