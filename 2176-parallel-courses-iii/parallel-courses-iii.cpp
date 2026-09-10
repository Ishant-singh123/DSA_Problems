class Solution {
public:
    void add_edges(vector<list<int>>&graph,int curr,int dest){
        graph[curr].push_back(dest);
    }
    int topo_BFS(queue<int>&q,vector<list<int>>&graph,unordered_set<int>&vis,vector<int>&deg,vector<int>&time,vector<int>&dp){
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(auto neigh:graph[curr]){
                if(vis.find(neigh)==vis.end()){
                    deg[neigh]--;
                    dp[neigh]=max(dp[neigh],dp[curr]+time[neigh-1]);
                    if(deg[neigh]==0){
                        q.push(neigh);
                        vis.insert(neigh);
                    }
                }
            }
        }
        return dp[dp.size()-1];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>deg(n+1,0);
        vector<list<int>>graph(n+1);
        for(int i=0;i<relations.size();i++){
            deg[relations[i][1]]++;
            add_edges(graph,relations[i][0],relations[i][1]);
        }
        queue<int>q;
        unordered_set<int>st;
        vector<int>dp(n+1,0);
        for(int i=1;i<deg.size();i++){
            if(deg[i]==0){
                q.push(i);
                st.insert(i);
                dp[i]=time[i-1];
            }
        }
        topo_BFS(q,graph,st,deg,time,dp);
        int ans=INT_MIN;
        for(int i=0;i<dp.size();i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};