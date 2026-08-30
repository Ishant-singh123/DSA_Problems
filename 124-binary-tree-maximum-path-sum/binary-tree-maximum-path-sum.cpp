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
    pair<int,int>solver(TreeNode *root){
        if(root==NULL){
            return {0,INT_MIN};
        }
        auto left_side=solver(root->left);
        auto right_side=solver(root->right);
        int left=max(0,left_side.first);
        int right=max(0,right_side.first);
        int upward=root->val+max(left,right);  // moving upward
        int through=root->val+left+right;   // throught root
        int ans=max(left_side.second,max(right_side.second,through));
        return {upward,ans};
    }
    int maxPathSum(TreeNode* root) {
        return solver(root).second;
    }
};