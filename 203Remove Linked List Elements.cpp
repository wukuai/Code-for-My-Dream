//移除所有某值的的结点
//https://leetcode.com/problems/remove-linked-list-elements
//细节一定要考虑周全，想像各种特殊输入，如删除1：[1] [1,1] [1,1,1,1,1] [1,1,1,1,2,3,4,5]
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL||(head->val==val&&head->next==NULL)) return NULL;
        while(head&&head->val==val){
            ListNode* toBeDelete=head;
            head=head->next;
            delete toBeDelete;
        }
        ListNode* node=head;
        while(node){
            if(node->val==val){
                if(node->next==NULL){
                    ListNode* temp=head;
                    while(temp->next!=node){
                        temp=temp->next;
                    }
                    temp->next=NULL;
                    delete node;
                    break;
                }
                else{
                    node->val=node->next->val;
                    ListNode* toBeDelete=node->next;
                    node->next=toBeDelete->next;
                    delete toBeDelete;
                }
                
            }
            else
                node=node->next;
        }
        return head;
    }
};
