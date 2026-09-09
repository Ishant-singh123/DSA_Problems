class Solution {
public:
    void bfs(vector<list<int>>&graph,vector<int>&deg,queue<int>&q,unordered_set<int>&st){
        
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(auto neigh:graph[curr]){
                if(st.find(neigh)==st.end()){
                    deg[neigh]--;
                    if(deg[neigh]==0){
                        q.push(neigh);
                        st.insert(neigh);
                    }
                }
            }
        }
    }
    void add_edges(vector<list<int>>&graph,int curr,int dest){
        graph[curr].push_back(dest);
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>out_deg(graph.size());
        vector<list<int>>gra(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                add_edges(gra,graph[i][j],i);
            }
        }
        for(int i=0;i<graph.size();i++){
            out_deg[i]=graph[i].size();
        }
        queue<int>q;
        unordered_set<int>vis;
        for(int i=0;i<out_deg.size();i++){
            if(out_deg[i]==0){
                q.push(i);
                vis.insert(i);
            }
        }
        bfs(gra,out_deg,q,vis);
        vector<int>ans;
        for(int i=0;i<out_deg.size();i++){
            if(out_deg[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};