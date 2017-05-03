//链表去重
//https://leetcode.com/problems/remove-duplicates-from-sorted-list
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
    ListNode* deleteDuplicates(ListNode* head) {
        //[1] [1,1,1,1]  [1,1,1,2,2] [1,1]
        if(head==NULL||head->next==NULL) return head;
        ListNode* node=head;
        while(node->next){
            if(node->next->val==node->val){
                ListNode* toBeDelete=node->next;
                node->next=node->next->next;
                delete toBeDelete;
            }
            else{
                node=node->next;
            }
            // if(node->next==NULL) break;//先用while(1) 写if ,再改写while(···)
        }
        return head;
    }
};
