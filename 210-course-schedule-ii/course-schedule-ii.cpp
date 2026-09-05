class Solution {
public:
    void add_edges(vector<list<int>>&graph,int curr,int dest){
        graph[curr].push_back(dest);
    }
    vector<int>degree(vector<list<int>>&graph){
        vector<int>deg(graph.size());
        for(int i=0;i<graph.size();i++){
            for(auto neigh:graph[i]){
                deg[neigh]++;
            }
        }
        return deg;
    }
    vector<int>topoBFS(vector<list<int>>&graph,vector<int>&deg){
        queue<int>q;
        unordered_set<int>st;
        for(int i=0;i<deg.size();i++){
            if(deg[i]==0){
                q.push(i);
                st.insert(i);
            }
        }
        vector<int>order;
        while(q.size()>0){
            int node=q.front();
            order.push_back(node);
            q.pop();
            for(auto neigh:graph[node]){
                if(st.find(neigh)==st.end()){
                    deg[neigh]--;
                    if(deg[neigh]==0){
                        st.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
        }
        return order;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>>graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            add_edges(graph,prerequisites[i][1],prerequisites[i][0]);            
        }
        vector<int>deg=degree(graph);

        vector<int>ans=topoBFS(graph,deg);
        if(ans.size()<numCourses){
            return {};
        }
        return ans;
    }
};