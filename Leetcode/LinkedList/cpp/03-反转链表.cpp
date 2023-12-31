/*
Author: CagurZhan
Description: 给定链表的头节点，翻转链表，返回头节点
*/
#include <iostream>
#include "ListNode.h"
using namespace std;

// 双指针法
ListNode* reverseList(ListNode*head){
    ListNode* tmp, *cur = head, *prev = nullptr;
    while(cur!=nullptr){
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}

// 递归法
ListNode* reverseListWithRecursion(ListNode*pre, ListNode*cur){
    if(cur == nullptr) return pre;
    ListNode*tmp = cur->next;
    cur->next = pre;
    reverseListWithRecursion(cur,tmp);
}

int main(){
    
    return 0;
}