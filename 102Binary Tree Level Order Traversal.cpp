//层次遍历二叉树
//https://leetcode.com/problems/binary-tree-level-order-traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //方法一，非递归实现，效率貌似不够高啊，待优化
 //vector里有vector,queue里有queue，第一次用，注意点：放进去之前记得判空！
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>V;
        queue<queue<TreeNode*>>Q;//TreeNode* 类型统一，别忘了星号
        queue<TreeNode*>qnow;
        if(root==NULL) return V;
        qnow.push(root);
        Q.push(qnow);
        qnow.pop();
        while(!Q.empty()){
            qnow=Q.front();
            Q.pop();
            vector<int>v;
            queue<TreeNode*>qnext;
            while(!qnow.empty()){
                TreeNode* temp=qnow.front();
                qnow.pop();//取出来后就记得pop
                v.push_back(temp->val);
                if(temp->left) qnext.push(temp->left);
                if(temp->right) qnext.push(temp->right);
            }
            V.push_back(v);
            v.clear();
            if(!qnext.empty())//注意！判空后再放进去！
                Q.push(qnext);
            while(!qnext.empty()){
                qnext.pop();
            }
        }
        return V;
    }
};
