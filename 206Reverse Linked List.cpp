//反转链表
//pre now nex  use three ListNodes
//多想几个特殊用例与边界条件，如两个结点，三个结点，到最后结点时候应该返回哪个结点
//https://leetcode.com/problems/reverse-linked-list
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;//在这里就把一些特殊情况处理掉
        ListNode* pre=head;
        ListNode* now=head->next;
        ListNode* nex=now->next;
        pre->next=NULL;
        while(1){//用while(1),跳出条件单独写，更方便！
            now->next=pre;
            pre=now;
            now=nex;
            if(nex==NULL){//只要a不是NULL，就可以取a->next，哪怕a->next==NULL
                break;
            }
            nex=nex->next;
        }
        return pre;
    }
};


//递归实现（不太理想，又写了个两个参数的递归函数）
//通用法则：先利用next得到下个点，再更改next
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recursive(NULL,head);
    }
    ListNode* recursive(ListNode* head,ListNode* nex){
        if(nex==NULL) return head;
        ListNode* newhead=nex;
        ListNode* newnex=nex->next;//关键点，先利用next得到下个点，再更改next
        nex->next=head;
        return recursive(newhead,newnex);//小心得，在有返回类型的递归函数中，应在递归调用前写个return，否则会出现无返回类型。
    }
};

//参考了讨论区，递归函数只用了一个参数，很棒！
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;//一定要加head->next==NULL
        ListNode* tail=reverseList(head->next);
        head->next->next=head;//head不会成为尾巴
        head->next=NULL;//这句主要是给原头指针用的
        return tail;
    }
};
