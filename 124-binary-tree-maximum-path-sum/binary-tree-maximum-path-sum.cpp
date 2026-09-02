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
    int solver(TreeNode *root,int &maxsum){
        if(root==NULL){
            return 0;
        }
        int left_side=solver(root->left,maxsum);
        int right_side=solver(root->right,maxsum);

        left_side=max(left_side,0);
        right_side=max(right_side,0);

        int path_through_root=root->val+left_side+right_side;

        maxsum=max(maxsum,path_through_root);

        return root->val+max(left_side,right_side);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        solver(root,maxsum);
        return maxsum;
    }
};