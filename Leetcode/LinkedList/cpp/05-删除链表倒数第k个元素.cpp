/*
Author: CagurZhan
Description: 删除链表倒数第K个数，并且返回链表的头节点。
使用一趟扫描完成。
*/
#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode* removeKthFromEnd(ListNode*head, int n){
    // 虚拟结点
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    // 快慢指针法，为了避免再使用一个指针，可以让slow指针指向要删除结点的上一个结点，即fast多走一个next
    ListNode* fast = dummyHead, *slow = dummyHead;
    // fast先走
    while(fast!=nullptr && n--){
        fast = fast->next;
    }
    fast = fast->next;
    // 快慢指针一起走
    while(fast!=nullptr){
        fast = fast->next;
        slow = slow->next;
    }
    // slow指针指向要删除结点的上一个结点
    ListNode * tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
    tmp = nullptr;
    return dummyHead->next;

}

int main(){
    
    return 0;
}