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
    TreeNode* build(vector<int>&pre,int prelo,int prehi,vector<int>&in,int inlo,int inhi){
        if(prelo>prehi){
            return NULL;
        }
        TreeNode *root=new TreeNode(pre[prelo]);
        if(prelo==prehi){
            return root;
        }
        int pivitol=-1;
        for(int i=inlo;i<=inhi;i++){
            if(pre[prelo]==in[i]){
                pivitol=i;
            }
        }
        int leftcount=pivitol-inlo;
        int rightcont=inhi-pivitol;
        root->left=build(pre,prelo+1,prelo+leftcount,in,inlo,pivitol-1);
        root->right=build(pre,prelo+leftcount+1,prehi,in,pivitol+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};