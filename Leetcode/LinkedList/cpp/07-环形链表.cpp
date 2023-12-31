/*
Author: CagurZhan
Description: 给定一个链表，返回一个链表开始入环的第一个结点。没有环就返回-1。
*/
#include <iostream>
#include "ListNode.h"
using namespace std;

// 快慢指针法
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast = fast->next->next;
        slow = slow->next;
        // 相遇，从相遇点和起点开始扫，指导第一个再次相遇的位置一定是起点
        // 推导，设初始点距离入环点距离是x，慢指针和快指针的相遇点距离入环点是y，从相遇结点再到入环点是z
            // 那么 slow指针走过了 x+y ，fast指针走过了 x + y +  n(y+z)，n是走过的圈数
            // 而，而总步数fast一定是比slow多了两倍的。即 2(x+y) = x+ y + n(y-z)
            // 解出 x =  n(y-z) -y = (n-1)y + z
            // 而n>=1，当n = 1的时候，x = z，即从起始点和相遇点出发各走一步的步长会相遇。
            // 而n>1，只是说多绕了n圈再相遇而已，同理
        if(slow == fast){
            ListNode* t1 = head;
            ListNode* t2 = slow;
            while(t1!=t2){
                t1 = t1->next;
                t2 = t2->next;
            }
            return t1;
        }
    }
    return nullptr;
}


int main(){
    
    return 0;
}