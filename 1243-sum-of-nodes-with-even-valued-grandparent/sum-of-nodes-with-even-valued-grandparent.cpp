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
    void tra(TreeNode *root,int &sum){
        if(root==NULL){
            return ;
        }
        if(root->val%2==0 && root->left!=NULL && root->left->left!=NULL){
            sum=sum+root->left->left->val;
        }
        if(root->val%2==0 && root->left!=NULL && root->left->right!=NULL){
            sum=sum+root->left->right->val;
        }
        if(root->val%2==0 && root->right!=NULL && root->right->left!=NULL){
            sum=sum+root->right->left->val;
        }
        if(root->val%2==0 && root->right!=NULL && root->right->right!=NULL){
            sum=sum+root->right->right->val;
        }
        tra(root->left,sum);
        tra(root->right,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        tra(root,sum);
        return sum;
    }
};