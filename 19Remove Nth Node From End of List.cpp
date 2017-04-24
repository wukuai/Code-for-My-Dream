//删除链表倒数第几个元素
//思考不周。。。能一次性写出free bug的代码就好了
//https://leetcode.com/submissions/detail/101062232/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL;
        // int len=0;
        ListNode* fast=head;
        ListNode* slow=head;
        n--;
        while(n--){
            fast=fast->next;//if n 《 len ?
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow->next==NULL){
            ListNode* temp=head;
            while(temp->next!=slow){
                temp=temp->next;
            }
            temp->next=NULL;
            delete slow;
            return head;
        }
        ListNode* toBeDelete=slow->next;
        slow->val=toBeDelete->val;
        slow->next=toBeDelete->next;
        delete toBeDelete;
        return head;
    }
};
