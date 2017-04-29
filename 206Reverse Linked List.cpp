//反转链表
//pre now nex  use three ListNodes
//多想几个特殊用例与边界条件，如两个结点，三个结点，到最后结点时候应该返回哪个结点
//https://leetcode.com/problems/reverse-linked-list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;//在这里就把一些特殊情况处理掉
        ListNode* pre=head;
        ListNode* now=head->next;
        ListNode* nex=now->next;
        pre->next=NULL;
        while(1){//用while(1),跳出条件单独写，更方便！
            now->next=pre;
            pre=now;
            now=nex;
            if(nex==NULL){//只要a不是NULL，就可以取a->next，哪怕a->next==NULL
                break;
            }
            nex=nex->next;
        }
        return pre;
    }
};
