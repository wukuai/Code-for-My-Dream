//删除链表中一个给定的结点
//O(1)的时间内删除，其实如果要删除尾部结点的话，还得O(n)时间
//https://leetcode.com/problems/delete-node-in-a-linked-list
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
    void deleteNode(ListNode* node) {
        ListNode* toBedelete=node->next;
        node->val=node->next->val;
        node->next=node->next->next;
        delete toBedelete;
    }
};
