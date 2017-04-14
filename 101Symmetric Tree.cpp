//判断二叉树是否对称
//https://leetcode.com/problems/symmetric-tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //虽然时间快，但是代码不够优雅
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        vector<int>v1,v2;
        fun1(root,v1);
        fun2(root,v2);
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        
        vector<int>lastv1,lastv2;
        last1(root,lastv1);
        last2(root,lastv2);
        for(int i=0;i<lastv1.size();i++){
            if(lastv1[i]!=lastv2[i]) return false;
        }
        
        return true;
    }
    void fun1(TreeNode* root,vector<int>& v1){
       if(root->left) fun1(root->left,v1);
       v1.push_back(root->val);
       if(root->right) fun1(root->right,v1);
    }
    
    void fun2(TreeNode* root,vector<int>& v2){
        if(root->right) fun2(root->right,v2);
        v2.push_back(root->val);
        if(root->left) fun2(root->left,v2);
    }
    
    void last1(TreeNode* root,vector<int>& lastv1){
       if(root->left) last1(root->left,lastv1);
       if(root->right) last1(root->right,lastv1);
       lastv1.push_back(root->val);
    }
    
    void last2(TreeNode* root,vector<int>& lastv2){
        if(root->right) last2(root->right,lastv2);
        if(root->left) last2(root->left,lastv2);
        lastv2.push_back(root->val);
    }
    
};


//优雅的代码
//注意是return ···&&fun(root1->left,root2->right)&&fun(root1->right,root2->left);
//想象画面，两边的，中间的，对称
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return fun(root->left,root->right);
    }
    bool fun(TreeNode* root1,TreeNode* root2){
        if(root1==NULL&&root2==NULL) return true;
        if(root1==NULL||root2==NULL) return false;
        return (root1->val==root2->val)&&fun(root1->left,root2->right)&&fun(root1->right,root2->left);
    }
};
