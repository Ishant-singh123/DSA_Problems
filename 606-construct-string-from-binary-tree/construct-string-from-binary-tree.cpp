/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solver(TreeNode *root,string &s){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            s=s+to_string(root->val);
            return ;
        }
        s=s+to_string(root->val);
        s=s+"(";
        solver(root->left,s);
        s=s+")";
        if(root->right!=NULL){
            s=s+"(";
            solver(root->right,s);
            s=s+")";
        }
    }
    string tree2str(TreeNode* root) {
        string ans="";
        solver(root,ans);
        return ans;
    }
};