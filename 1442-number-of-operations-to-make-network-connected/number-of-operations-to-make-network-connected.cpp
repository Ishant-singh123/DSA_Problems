class Solution {
public:
    int find(vector<int>&parent,int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent,parent[x]);
    }
    void unite(vector<int>&parent,vector<int>&rank,int a,int b){
        a=find(parent,a);
        b=find(parent,b);

        if(a==b){
            return ;
        }
        if(rank[a]>=rank[b]){
            parent[b]=a;
            rank[a]++;
        }
        else{
            parent[a]=b;
            rank[b]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<connections.size();i++){
            unite(parent,rank,connections[i][0],connections[i][1]);
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(find(parent,i));
        }
        if(st.size()==n){
            return -1;
        }
        return st.size()-1;
    }
};