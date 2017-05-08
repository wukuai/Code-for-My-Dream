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
    bool isPalindrome(ListNode* head) {
       // [1,2,3,2,1]
        if(head==NULL||head->next==NULL) return true;
        //用快慢指针的方法找中点（若是偶数个结点，则找的是中点的前一个结点）
        ListNode* slow=head;//注意星号的位置?同时命名两个？
        ListNode* fast=head;
        while(fast&&fast->next&&fast->next->next){//****
            slow=slow->next;
            fast=fast->next->next;
        }
        while(fast->next) fast=fast->next;
        ListNode* mid=slow;//?
        ListNode* p1=head;
        ListNode* p2=fast;
        reverse(slow);
        if(p1->val!=p2->val) {
            return false;
        }
        while(1){
            p1=p1->next;
            p2=p2->next;
            if(p1->val!=p2->val) return false;
            if(p1==mid) break;
        }
        return true;
    }
    void reverse(ListNode* head){//注意另外递归实现的翻转
        if(head==NULL||head->next==NULL) return;
        if(head->next->next==NULL) {head->next->next=head;return;}
        
        ListNode* pre=head;
        ListNode* now=head->next;
        ListNode* nex=head->next->next;
        while(nex){
            now->next=pre;
            pre=now;
            now=nex;
            nex=nex->next;
        }
        now->next=pre;
        return;
    }
};
