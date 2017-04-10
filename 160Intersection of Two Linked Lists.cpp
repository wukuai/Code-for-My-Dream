 //两个链表的交点
 //想想图，两个链表相交后就一直在一起了
 //细节，这里的指针，不可以用++，而是root=root->next;
 //https://leetcode.com/problems/intersection-of-two-linked-lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA=0,lengthB=0;
        ListNode *tempA=headA;
        while(tempA){//判断是否为NULL,不要加*号
            tempA=tempA->next;
            lengthA++;
        }
        ListNode *tempB=headB;
        while(tempB){
            tempB=tempB->next;
            lengthB++;
        }
        int k=abs(lengthA-lengthB);
        tempA=headA;
        tempB=headB;
        if(lengthA>lengthB){
            while(k--){
                tempA=tempA->next;
            }
        }
        else{
            while(k--){
                tempB=tempB->next;
            }
        }
        while(tempA!=tempB){//这样写简洁，免得判断了
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};
