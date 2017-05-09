//判断两棵二叉树是否一样
//https://leetcode.com/problems/same-tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL) return true;
        if(p==NULL||q==NULL) return false;
        if(p->val==q->val) return(isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
        else return false;
    }
};

//两行版，优美！
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL||q==NULL) return p==q;
        return (p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
}
//一行版，更优美！
bool isSameTree(TreeNode* p, TreeNode* q) {
        return (p==NULL||q==NULL) ? (p==q):(p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
}
