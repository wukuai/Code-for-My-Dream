//二叉搜索树的第K小节点
//二叉搜索树特点：中序遍历序列递增
//but 效率较低，不用vector？不用递归？
//https://leetcode.com/problems/kth-smallest-element-in-a-bst
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        findKth(root,v);
        return v[k-1];
    }
    vector<int> findKth(TreeNode* root,vector<int>& v){
        if(root->left)
            findKth(root->left,v);
        v.push_back(root->val);
        if(root->right)
            findKth(root->right,v);
        return v;
    }
};
