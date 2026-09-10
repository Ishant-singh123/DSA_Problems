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
    // {sum,size}
    tuple<int,int,int> solver(TreeNode *root){
        if(root==NULL){
            return {0,0,0};
        }
        auto [suml,countl,ans1]=solver(root->left);
        auto [sumr,countr,ans2]=solver(root->right);
        if(((suml+sumr+root->val)/(countl+countr+1))==root->val){
            return {suml+sumr+root->val,countl+countr+1,ans1+ans2+1};            
        }
        return {suml+sumr+root->val,countl+countr+1,ans1+ans2};
    }
    int averageOfSubtree(TreeNode* root) {
        auto  [sum,count,ans]=solver(root);
        return ans;
    }
};