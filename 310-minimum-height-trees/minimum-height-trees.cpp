class Solution {
public:
// Why DSU is NOT the pattern

// DSU is mainly useful when the question asks:
// Are two nodes connected?
// Merge components
// Number of connected components
// Detect cycle
// Kruskal/MST
// Dynamic connectivity



// Clue in the question	Pattern to think of
// Find the center(s) of a tree	                                   Leaf trimming
// Find the root that gives minimum height	                       Leaf trimming
// Repeatedly remove leaves	                                       Leaf trimming
// Remove nodes from the outside toward the middle 	               Leaf trimming
// Find the last 1 or 2 nodes remaining	                           Leaf trimming
// A tree is given, and you need to find its diameter/center	Consider tree center

// then Leaf Trimming / Topological BFS on an Undirected Tree
    void add_edge(vector<list<int>>&graph,int curr,int dest){
        graph[curr].push_back(dest);
        graph[dest].push_back(curr);
    }

    vector<int> trimming_bfs(queue<int>&q,vector<list<int>>&graph,vector<int>&deg,unordered_set<int>&vis){
        int rem=graph.size();
        while(rem>2){
            int sz=q.size();  // ye queue ke size aalag se store karna h then inner loop lagana h 
            rem=rem-sz;
            while(sz>0){
                int curr=q.front();
                q.pop();
                for(auto neigh:graph[curr]){
                    if(vis.find(neigh)==vis.end()){
                        deg[neigh]--;
                        if(deg[neigh]==1){
                            q.push(neigh);
                            vis.insert(neigh);
                        }
                    }
                }
                sz--;
            }
        }
        vector<int>ans;
        while(q.size()>0){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<int>degree(n,0);
        vector<list<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            add_edge(graph,edges[i][0],edges[i][1]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        queue<int>q;
        unordered_set<int>vis;
        for(int i=0;i<degree.size();i++){
            if(degree[i]==1){
                q.push(i);
                vis.insert(i);
            }
        }
        return trimming_bfs(q,graph,degree,vis);
    }
};