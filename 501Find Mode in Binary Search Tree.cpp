//BST中出现次数最多的结点
//https://leetcode.com/problems/find-mode-in-binary-search-tree
//利用中序遍历的性质，记录好次数
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
    vector<int> findMode(TreeNode* root) {
      vector<int>ans;
      if(root==NULL) return ans;
      int max=0;
      int pre=0;
      int cnt=0;
      inOrder(root,max,pre,cnt);
      cnt=-1;
      findMaxNode(root,ans,max,pre,cnt);
      return ans;
    }
    void inOrder(TreeNode* root,int& max,int& pre,int& cnt){
        if(root->left)
            inOrder(root->left,max,pre,cnt);
        if(max==0||root->val==pre){
            if(max==0) pre=root->val;
            cnt++;
            max=max>cnt?max:cnt;//?
        }
        else 
            cnt=1,pre=root->val;
        if(root->right)
            inOrder(root->right,max,pre,cnt);
    }
    void findMaxNode(TreeNode* root,vector<int>& ans,int& max,int& pre,int& cnt){
        if(root->left) findMaxNode(root->left,ans,max,pre,cnt);
        if(cnt==-1||root->val==pre){
            if(cnt==-1) cnt=0,pre=root->val;
            cnt++;
        }
        else if(root->val!=pre){
            pre=root->val;
            cnt=1;
        }
        if(cnt==max){//放到后面来，防止当cnt==max==1的情况！
                ans.push_back(root->val);
        }
        if(root->right) findMaxNode(root->right,ans,max,pre,cnt);
    }
};
