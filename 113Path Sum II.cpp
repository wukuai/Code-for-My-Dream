//返回二叉树和路径
//传引用，记得pop_back()
//https://leetcode.com/problems/path-sum-ii
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ans;
        vector<int>path;
        if(root==NULL) return ans;
        findPath(root,path,ans,0,sum);
        return ans;
    }
    void findPath(TreeNode* root,vector<int>& path,vector<vector<int>>& ans,int sumnow,int sum){
        sumnow+=root->val;
        path.push_back(root->val);
        if(sumnow==sum&&root->left==NULL&&root->right==NULL){
            ans.push_back(path);
        }
        if(root->left) findPath(root->left,path,ans,sumnow,sum);
        if(root->right) findPath(root->right,path,ans,sumnow,sum);
        path.pop_back();//关键点，弹出去，理解好递归，先进后出
    }
};
