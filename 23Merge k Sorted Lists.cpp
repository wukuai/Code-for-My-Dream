//方法一，一个总的，依次两两合并，时间复杂度O(n*k^2)，链表平均长度为n，k个链表,406ms。。。。
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

//优化，29ms，平均分摊合并，分治，时间复杂度？
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n=lists.n();
    if(n==0) return NULL;
    int i=0,j=n-1;
    while(n!=1){
        lists[i]=mergeTwoLists(lists[i],lists[j]);
        i++,j--;
        if(i>=j){//注意当n为奇数的时候=也可以
            if(n%2==0) n=n/2;
            else n=n/2+1;//注意这里，当原来n为奇数的时候，别忘了+1；多想例子，如n=3 and n=4
            i=0,j=n-1;
        }
    }
    return lists[0];
}
