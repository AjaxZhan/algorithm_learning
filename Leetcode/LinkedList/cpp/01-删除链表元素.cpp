/*
Author: CagurZhan
Description: 删除链表元素
*/
#include <iostream>
#include <ListNode.h>
using namespace std;

ListNode* removeItemByVal(ListNode* head,int val){
    // 虚拟头节点
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* p = dummyHead;
    while(p->next!=nullptr){
        if(p->next->val == val){
            ListNode*q = p->next;
            p->next = p->next->next;
            delete q;
        }else{
            p = p->next;
        }
    }
    // C++自己管理内存，删掉虚拟头节点
    head = dummyHead->next;
    delete dummyHead;
    return head;
}

int main(){
    
    return 0;
}