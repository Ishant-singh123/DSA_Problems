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
// This is a Tree DP + DFS problem. The main pattern is:

// When the answer depends on whether the current node is selected or not, return two DP states from every node.

// The problem asks for the maximum money you can rob, but you cannot rob both a parent and its direct child. 

// 1. How to identify this pattern?
// Whenever you see:
// A tree
// A maximum/minimum/count question
// A restriction involving the parent and child
// A choice: take the current node OR skip it

// Think:
// Tree DP → DFS → Return multiple states.
// This is similar to House Robber I (LC 198), but instead of houses in a line, the houses are arranged in a tree.

// 2. Why do we need two states?
// For every node, ask two questions:
// 1. What is the maximum money if I ROB this node?
// 2. What is the maximum money if I DO NOT ROB this node?

// Let: dfs(node) = {rob, skip}

// Where:
// rob = maximum money when the current node is robbed
// skip = maximum money when the current node is not robbed

// Important: These are not simply the answers of the left and right subtrees. They are answers under a condition about the current node.



    pair<int,int> solver(TreeNode *root){
        if(root==NULL){
            return {0,0};
        }
        auto left=solver(root->left);
        auto right=solver(root->right);

        int rob=root->val+left.second+right.second;
        int skip=max(left.first,left.second)+max(right.first,right.second);
        return {rob,skip};

    }
    int rob(TreeNode* root) {
        auto p=solver(root);
        return max(p.first,p.second);   
    }
};