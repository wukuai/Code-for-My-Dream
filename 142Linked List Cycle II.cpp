//返回链表环的入口节点
//一个指针先走l步，l为环的节点数，另一个指针再开始走，相遇时即为入口
//思考 L为链表长度，L-l为非环节点，同时L-l也为快指针后面走到入口的步数 想象图即可
//https://leetcode.com/problems/linked-list-cycle-ii
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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode *p1=head;
        ListNode *p2=head->next->next;
        while(p1&&p2&&p2->next&&p1!=p2){
            p1=p1->next;
            p2=p2->next->next;
        }
        if(!(p1==p2&&p1)) return NULL;//p1!=NULL !
        int cnt=1;
        p1=p1->next;
        while(p1!=p2){
            p1=p1->next;
            cnt++;
        }
        p1=head;
        p2=head;
        while(cnt--) p1=p1->next;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};
