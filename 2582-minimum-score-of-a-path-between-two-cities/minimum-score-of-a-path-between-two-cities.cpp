class Solution {
public:
    void add_edge(vector<list<pair<int,int>>>&graph,int curr,int dest,int weight){
        graph[curr].push_back({dest,weight});
        graph[dest].push_back({curr,weight});
    }
    void dfs(vector<list<pair<int,int>>>&graph,int curr,int dest,unordered_set<int>&st,int &ans){
        st.insert(curr);
        for(auto neigh:graph[curr]){
            ans=min(ans,neigh.second);

            if(st.find(neigh.first)==st.end()){
                dfs(graph,neigh.first,dest,st,ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=INT_MAX;
        vector<list<pair<int,int>>>graph(n+1);
        for(int i=0;i<roads.size();i++){
            add_edge(graph,roads[i][0],roads[i][1],roads[i][2]);
        }
        unordered_set<int>st;
        dfs(graph,1,4,st,ans);
        return ans;
    }
};