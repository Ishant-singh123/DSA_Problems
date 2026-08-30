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
    int widthOfBinaryTree(TreeNode* root) {
       queue<pair<TreeNode*,unsigned long long>>q;
       q.push({root,0});
       unsigned long long maxlen=0;
        while(q.size()>0){
            unsigned long long l=q.front().second;
            unsigned long long r=q.back().second;
            maxlen=max(maxlen,r-l+1);
            int n=q.size();
            while(n>0){
                TreeNode *temp=q.front().first;
                unsigned long long indx=q.front().second;
                q.pop();
                if(temp->left!=NULL){
                    q.push({temp->left,2*indx+1});
                }
                if(temp->right!=NULL){
                    q.push({temp->right,2*indx+2});
                }
                n--;
            }
        } 
        return maxlen;
    }
};