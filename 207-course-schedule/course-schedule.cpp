class Solution {
public:
    void add_edge(vector<list<int>>&graph,int curr,int dest){
        graph[curr].push_back(dest);
    }
    vector<int> deg(vector<list<int>>&graph){
        vector<int>in_deg(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto neigh:graph[i]){
                in_deg[neigh]++;
            }
        }
        return in_deg;
    }

    void topological_sort(vector<list<int>>&graph,queue<int>&q,vector<int>&in_deg,unordered_set<int>&st){
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            // cout<<curr<<" ";
            for(auto neigh:graph[curr]){
                if(st.find(neigh)==st.end()){
                    in_deg[neigh]--;
                    if(in_deg[neigh]==0){
                        st.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>>graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            add_edge(graph,prerequisites[i][1],prerequisites[i][0]);
        }
        vector<int>in_deg=deg(graph);
        queue<int>q;
        unordered_set<int>st;
        for(int i=0;i<in_deg.size();i++){
            if(in_deg[i]==0){
                q.push(i);
                st.insert(i);
            }
        }
        topological_sort(graph,q,in_deg,st);
        if(st.size()==numCourses){
            return true;
        }
        return false;
    }
};