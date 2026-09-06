class Solution {
public:
    void add_edges(vector<list<int>>&graph,int &curr,int &dest){
        graph[curr].push_back(dest);
        graph[dest].push_back(curr);
    }
    void dfs(vector<list<int>>&graph,int curr,unordered_set<int>&vis){
        vis.insert(curr);
        for(auto neigh:graph[curr]){
            if(vis.find(neigh)==vis.end()){
                dfs(graph,neigh,vis);
            }
        }
    }

    int component(vector<list<int>>&graph){
        unordered_set<int>vis;
        int count=0;
        for(int i=0;i<graph.size();i++){
            if(vis.find(i)==vis.end()){
                dfs(graph,i,vis);
                count++;
            }
        }
        return count;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<list<int>>graph(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    add_edges(graph,i,j);
                }
            }
        }
        return component(graph);
    }
};