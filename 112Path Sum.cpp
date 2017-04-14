//寻找二叉树和的路径
//学会传引用，避免了全局变量，显得更专业！
//注意路径的理解，开头是根，末尾一定要是叶子
//https://leetcode.com/problems/path-sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        bool flag=false;
        findSum(root,0,sum,flag);
        return flag;
    }
    void findSum(TreeNode* root,int sumnow,int sum,bool& flag){//传引用
        if(flag) return;
        sumnow+=root->val;
        if(sumnow==sum&&root->left==NULL&&root->right==NULL) flag=true;//同时还要是叶子
        if(root->left){
            findSum(root->left,sumnow,sum,flag);
        }
        if(root->right){
            findSum(root->right,sumnow,sum,flag);            
        }
    }
};


//优雅！叹服！
//not . but -> !
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        if(root->left==NULL&&root->right==NULL) return sum==root->val;
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);   
    }
};
