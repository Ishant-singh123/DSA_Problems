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
    int level(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        return 1+max(level(root->left),level(root->right));
    }
    void foreach(TreeNode *root,int le,int curr,int &sum){
        if(root==NULL){
            return ;
        }
        if(le==curr){
            sum=sum+root->val;
        }
        foreach(root->left,le,curr+1,sum);
        foreach(root->right,le,curr+1,sum);
    }
    void bfs(TreeNode *root,int &indx){
        int n=level(root);
        int maxsum=INT_MIN;
        for(int i=1;i<=n;i++){
            int sum=0;
            foreach(root,i,1,sum);
            if(maxsum<sum){
                maxsum=sum;
                indx=i;
            }
        }
    }
    int maxLevelSum(TreeNode* root) {
        int ans=0;
        bfs(root,ans);
        return ans;
    }
};