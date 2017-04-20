//判断链表是否有环
//while(p1&&p2&&p2->next&&p1!=p2)
//https://leetcode.com/problems/linked-list-cycle
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
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return false;
        ListNode *p1=head;
        ListNode *p2=head->next;
        while(p1&&p2&&p2->next&&p1!=p2){
        //while(p1!=NULL&&p2!=NULL&&p2->next!=NULL&&p1!=p2){ 
        //make sure that p2->next!=NULL is important,because we will use p2->next->next
            p1=p1->next;
            p2=p2->next->next;
        }
        if(p1==p2&&p1!=NULL) return true;
        else return false;
        
    }
};
