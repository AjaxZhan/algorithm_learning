/*
Author: CagurZhan
Description: 两两交换链表中的结点，返回交换后的头结点
*/
#include <iostream>
#include "ListNode.h"
using namespace std;

// 同样采用哨兵结点
// 注意判断空的条件！后两个结点都非空，才继续走
ListNode* swapPairs(ListNode* head){
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *cur = dummyHead;
    while(cur->next!=nullptr && cur->next->next!=nullptr){
        ListNode *t1 = cur->next , *t2 = cur->next->next->next;
        cur->next = t1->next;
        cur->next->next = t1;
        t1->next = t2;
        cur = cur->next->next;
    }

    return dummyHead->next;
}

int main(){
    
    return 0;
}