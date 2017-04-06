//方法一，一个总的，依次两两合并，时间复杂度O(n*k^2)，链表平均长度为n，k个链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size=lists.size();
        if(size==0) return NULL;
        ListNode* temp=lists[0];
        for(int i=1;i<size;i++){
            temp=mergeTwoLists(temp,lists[i]);   
        }
        return temp;
    }
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
            l1->next=mergeTwoLists(l1->next,l2);
        }
        else{
            temp=l2;
            l2->next=mergeTwoLists(l1,l2->next);
        }
        return temp;
    }
};
