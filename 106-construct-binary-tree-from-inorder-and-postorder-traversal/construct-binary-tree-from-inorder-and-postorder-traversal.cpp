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
    TreeNode* build(vector<int>&pos,int poshi, int poslo,vector<int>&in,int inlo,int inhi){
        if(poslo<poshi || inlo>inhi){
            return NULL;
        }
        TreeNode *root=new TreeNode(pos[poslo]);
        if(poslo==poshi){
            return root;
        }
        int pivitol=-1;
        for(int i=inlo;i<=inhi;i++){
            if(in[i]==pos[poslo]){
                pivitol=i;
            }
        }
        int leftcount=pivitol-inlo;
        int rightcount=inhi-pivitol;
        root->left=build(pos,poshi,poslo-rightcount-1,in,inlo,pivitol-1);
        root->right=build(pos,poshi+leftcount,poslo-1,in,pivitol+1,inhi);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }
};