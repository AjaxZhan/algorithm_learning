/*
Author: CagurZhan
Description: 给两个链表，找出两个链表相交的起始结点，如果没有，返回nullptr
数据保证链表不存在环
*/
#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 先获得链表长度
    int lenA = getListLength(headA);
    int lenB = getListLength(headB);
    
    ListNode *p = headA;
    ListNode *q = headB;

    while(lenA > lenB){
        p = p->next;
        lenA -- ;
    }
    while(lenA < lenB){
        q = q->next;
        lenB -- ;
    }
    while(q!=nullptr && p!=nullptr){
        if(p == q) return p;
        p = p->next;
        q = q->next;
    }
    return nullptr;
    
}

int getListLength(ListNode* head){
    int res=0;
    ListNode *p = head;
    while(p!=nullptr){
        res++;
        p = p->next;
    }
    return res;
}

int main(){
    
    return 0;
}