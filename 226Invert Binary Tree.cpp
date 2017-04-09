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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;//注意鲁棒性；另理解函数先后的返回值，哪个是需要返回给最开始调用函数的
        if(root->left==NULL&&root->right==NULL) return root;//可加可不加，加上更直观
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        if(root->left!=NULL)
             invertTree(root->left);
        if(root->right!=NULL)
            invertTree(root->right);
        return root;//理解函数先后的返回值，哪个是需要返回给最开始调用函数的
    }
};
