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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        map<int,vector<int>>mp;
        q.push({root,0});
        pair<TreeNode*,int>p;
        while(q.size()>0){
            int n=q.size();
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            while(n>0){
                TreeNode *temp=q.front().first;
                int level=q.front().second;
                q.pop();
                pq.push({temp->val,level});
                if(temp->left!=NULL){
                    p.first=temp->left;
                    p.second=level-1;
                    q.push(p);
                }
                if(temp->right!=NULL){
                    p.first=temp->right;
                    p.second=level+1;
                    q.push(p);
                }
                n--;
            }
            while(pq.size()>0){
                mp[pq.top().second].push_back(pq.top().first);
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};