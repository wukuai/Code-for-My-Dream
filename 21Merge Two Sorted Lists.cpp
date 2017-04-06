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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode* temp=NULL;
        if(l1->val<l2->val){
            temp=l1;
            l1->next=mergeTwoLists(l1->next,l2);//not return
        }
        else{
            temp=l2;
            l2->next=mergeTwoLists(l1,l2->next);
        }
        return temp;
    }
};
//PS：don't use '.' to take the place of '->'
